#ifndef FINAL_PROJECT_H
#define FINAL_PROJECT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 10;
const int NUM_SHIPS = 5;
extern const int SHIP_SIZES[NUM_SHIPS];
extern const string SHIP_NAMES[NUM_SHIPS];

struct Coordinate { // represents a coordinate on the board
    int row;
    int col;
};

int parseCol(const string& input);

class Ship {
private:
    int size;
    int hits;
    Coordinate* positions;
    bool* hitParts;
    string name;

public:
    Ship(int size, string name);
    void setPosition(int index, Coordinate coord);
    bool hit(int row, int col);
    bool isSunk();
    string getName();
    ~Ship();
};

class Board {
private:
    char** grid; // 2D grid of characters for ship, hit, and miss

public:
    Board();
    void print();
    bool isEmpty(int row, int col);
    void markShip(int row, int col);
    void markHit(int row, int col);
    void markMiss(int row, int col);
    char get(int row, int col);
    void revealBoard();
    ~Board();
};

class Player {
private:
    string name;
    Board* ownBoard;
    Board* opponentBoard;
    vector<Ship*> ships;

public:
    Player(string n);
    void placeShips();
    bool attack(Player* opponent);
    bool hasShipsRemaining();
    void showOwnBoard();
    void showopponentBoard();
    ~Player();
};

#endif
