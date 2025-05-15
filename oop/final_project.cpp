#include "final_project.h"

const int SHIP_SIZES[NUM_SHIPS] = {5, 4, 3, 3, 2}; // size of the board (10x10)
const string SHIP_NAMES[NUM_SHIPS] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};

int parseCol(const string& input) {
    int col = 0;
    for (int i = 1; i < input.length(); ++i) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            col = col * 10 + (c - '0');
        } else {
            return -1;
        }
    }
    return col;
}

Ship::Ship(int size, string name) : size(size), hits(0), name(name) {
    positions = new Coordinate[size];
    hitParts = new bool[size];
    for (int i = 0; i < size; ++i) hitParts[i] = false;
}

void Ship::setPosition(int index, Coordinate coord) {
    if (index >= 0 && index < size)
        positions[index] = coord;
}

bool Ship::hit(int row, int col) {
    for (int i = 0; i < size; i++) {
        if (positions[i].row == row && positions[i].col == col && !hitParts[i]) {
            hitParts[i] = true;
            hits++;
            return true;
        }
    }
    return false;
}

bool Ship::isSunk() {
    return hits >= size;
}

string Ship::getName() {
    return name;
}

Ship::~Ship() {}

Board::Board() {
    grid = new char*[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i) {
        grid[i] = new char[BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; ++j)
            grid[i][j] = '.';
    }
}

void Board::print() {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool Board::isEmpty(int row, int col) {
    return grid[row][col] == '.';
}

void Board::markShip(int row, int col) {
    grid[row][col] = 'S';
}

void Board::markHit(int row, int col) {
    grid[row][col] = 'X';
}

void Board::markMiss(int row, int col) {
    grid[row][col] = 'O';
}

char Board::get(int row, int col) {
    return grid[row][col];
}

void Board::revealBoard() {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            char cell = grid[i][j];
            cout << cell << " ";
        }
        cout << endl;
    }
}

Board::~Board() {}

Player::Player(string n) : name(n) {
    ownBoard = new Board();
    opponentBoard = new Board();
}

void Player::placeShips() {
    cout << name << ", place your ships:" << endl;
    for (int s = 0; s < NUM_SHIPS; s++) {
        Ship* ship = new Ship(SHIP_SIZES[s], SHIP_NAMES[s]);
        ships.push_back(ship);

        string input;
        char dir;
        int row, col;
        bool valid;

        do {
            valid = true;
            cout << "Enter starting position (e.g. A0-J9) and direction (H/V) for " << SHIP_NAMES[s] << " (size " << SHIP_SIZES[s] << "): ";
            cin >> input >> dir;
            row = input[0] - 'A';
            col = parseCol(input);

            for (int i = 0; i < SHIP_SIZES[s]; i++) {
                int r = row + (dir == 'V' ? i : 0);
                int c = col + (dir == 'H' ? i : 0);
                if (r >= BOARD_SIZE || c >= BOARD_SIZE || !ownBoard->isEmpty(r, c)) {
                    valid = false;
                    break;
                }
            }

            if (!valid) cout << "Invalid position. Try again.\n";

        } while (!valid);

        for (int i = 0; i < SHIP_SIZES[s]; i++) {
            int r = row + (dir == 'V' ? i : 0);
            int c = col + (dir == 'H' ? i : 0);
            ship->setPosition(i, {r, c});
            ownBoard->markShip(r, c);
        }
    }
}

bool Player::attack(Player* opponent) {
    string input;
    cout << name << ", enter attack coordinates (e.g. A0-J9): ";
    cin >> input;
    int row = input[0] - 'A';
    int col = parseCol(input);

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE ||
        opponentBoard->get(row, col) == 'X' || opponentBoard->get(row, col) == 'O') {
        cout << "Invalid or repeated attack. Try again.\n";
        return attack(opponent);
    }

    for (int i = 0; i < opponent->ships.size(); i++) {
        Ship* ship = opponent->ships[i];
        if (ship->hit(row, col)) {
            opponent->ownBoard->markHit(row, col);
            opponentBoard->markHit(row, col);
            cout << "Hit!" << endl;
            if (ship->isSunk()) {
                cout << "You sunk the " << ship->getName() << "!" << endl;
            }
            return opponent->hasShipsRemaining();
        }
    }

    opponent->ownBoard->markMiss(row, col);
    opponentBoard->markMiss(row, col);
    cout << "Miss!" << endl;
    return opponent->hasShipsRemaining();
}

bool Player::hasShipsRemaining() {
    for (int i = 0; i < ships.size(); i++) {
        Ship* ship = ships[i];
        if (!ship->isSunk()) return true;
    }
    return false;
}

void Player::showOwnBoard() {
    ownBoard->revealBoard();
}

void Player::showopponentBoard() {
    opponentBoard->revealBoard();
}

Player::~Player() {}
