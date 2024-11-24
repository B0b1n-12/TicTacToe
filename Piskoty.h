#ifndef PISKOTY_H
#define PISKOTY_H

#include <vector>
#include "NPC.h"

class Piskoty {
private:
    std::vector<std::vector<int>> board; // Game board
    int boardSize;                       // Board size
    bool gameRunning;                    // Game state
    int currentPlayer;                   // Current player (0 = player, 1 = NPC)
    NPC npc;                             // NPC instance

    void displayBoard() const;            // Display the game board
    void playerMove();                    // Handle player's move
    void npcMove();                       // Handle NPC's move
    bool validateInput(int row, int col) const; // Validate move
    void checkWin();                      // Check for a win or draw
    bool checkRows() const;               // Check rows for win
    bool checkCols() const;               // Check columns for win
    bool checkDiagonals() const;          // Check diagonals for win

public:
    Piskoty(int size);  // Constructor
    void startGame();   // Start the game
};

#endif
