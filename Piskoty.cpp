#include "Piskoty.h"
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

using namespace std;

Piskoty::Piskoty(int size) : boardSize(size), gameRunning(true), currentPlayer(0) {
    board.resize(boardSize, vector<int>(boardSize, 8)); // Initialize board with empty cells (8)
}

void Piskoty::startGame() {
    while (gameRunning) {
        displayBoard();
        if (currentPlayer == 0) {
            playerMove();
        }
        else {
            npcMove();
        }

        checkWin(); // Check for win or draw
        currentPlayer = 1 - currentPlayer; // Switch players
    }
}

void Piskoty::displayBoard() const {
    cout << "   ";
    for (int i = 0; i < boardSize; ++i) cout << i << " "; // Column headers
    cout << endl;

    for (int i = 0; i < boardSize; ++i) {
        cout << i << " "; // Row header
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == 8) {
                cout << "- ";
            }
            else if (board[i][j] == 0) {
                cout << "X ";
            }
            else {
                cout << "O ";
            }
        }
        cout << endl;
    }
}

void Piskoty::playerMove() {
    int row, col;
    cout << "Enter your move (row and column): ";
    cin >> row >> col;

    if (validateInput(row, col)) {
        board[row][col] = 0; // Player plays as X
    }
    else {
        cout << "Invalid move! Try again." << endl;
        playerMove(); // Retry
    }
}

void Piskoty::npcMove() {
    cout << "NPC is making a move..." << endl;
    pair<int, int> move = npc.getMove(board);
    board[move.first][move.second] = 1; // NPC plays as O
}

bool Piskoty::validateInput(int row, int col) const {
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize) {
        cout << "Out of bounds! Choose a valid cell." << endl;
        return false;
    }
    if (board[row][col] != 8) {
        cout << "Cell already occupied!" << endl;
        return false;
    }
    return true;
}

void Piskoty::checkWin() {
    if (checkRows() || checkCols() || checkDiagonals()) {
        displayBoard();
        cout << (currentPlayer == 0 ? "Player" : "NPC") << " wins!" << endl;
        gameRunning = false;
    }
}

bool Piskoty::checkRows() const {
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][0] != 8) {
            bool win = true;
            for (int j = 1; j < boardSize; ++j) {
                if (board[i][j] != board[i][j - 1]) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }
    return false;
}

bool Piskoty::checkCols() const {
    for (int j = 0; j < boardSize; ++j) {
        if (board[0][j] != 8) {
            bool win = true;
            for (int i = 1; i < boardSize; ++i) {
                if (board[i][j] != board[i - 1][j]) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }
    return false;
}

bool Piskoty::checkDiagonals() const {
    // Main diagonal
    if (board[0][0] != 8) {
        bool win = true;
        for (int i = 1; i < boardSize; ++i) {
            if (board[i][i] != board[i - 1][i - 1]) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    // Anti-diagonal
    if (board[0][boardSize - 1] != 8) {
        bool win = true;
        for (int i = 1; i < boardSize; ++i) {
            if (board[i][boardSize - i - 1] != board[i - 1][boardSize - i]) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    return false;
}
