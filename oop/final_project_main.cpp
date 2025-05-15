#include "final_project.h"

int main() {
    cout << "Welcome to Battleship!\n";

    Player p1("Player 1"); // Create Player 1
    Player p2("Player 2"); // Create Player 2

    p1.placeShips(); // Player 1 places ships
    p2.placeShips(); // Player 2 places ships

    bool player1Turn = true; // Track whose turn it is
    while (true) {
        if (player1Turn) {
            if (!p1.attack(&p2)) { // Player 1 attacks
                cout << "Player 1 wins!\n";
                break;
            }
        } else {
            if (!p2.attack(&p1)) { // Player 2 attacks
                cout << "Player 2 wins!\n";
                break;
            }
        }
        player1Turn = !player1Turn; // Switch turns
    }

    cout << "Game Over.\n";
    cout << "\nFinal Board States:\n";

    cout << "Player 1's Board (ships and where Player 2 attacked):\n";
    p1.showOwnBoard();
    cout << "\nPlayer 1's Attacks on Player 2:\n";
    p1.showopponentBoard();

    cout << "\nPlayer 2's Board (ships and where Player 1 attacked):\n";
    p2.showOwnBoard();
    cout << "\nPlayer 2's Attacks on Player 1:\n";
    p2.showopponentBoard();

    return 0;
}
