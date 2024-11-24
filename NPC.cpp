#include "NPC.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

// NPC generates a random move
std::pair<int, int> NPC::getMove(const std::vector<std::vector<int>>& board) {
    int size = board.size();
    int row, col;

    // Generate a random move until an empty cell is found
    do {
        row = rand() % size;
        col = rand() % size;
    } while (board[row][col] != 8);

    return { row, col };
}
