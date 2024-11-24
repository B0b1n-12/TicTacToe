#include "Piskoty.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    int size;
    cout << "Enter the size of the game board: ";
    cin >> size;

    if (size < 3) {
        cout << "The board size must be at least 3. Setting size to 3." << endl;
        size = 3;
    }

    Piskoty game(size);
    game.startGame();

    return 0;
}
