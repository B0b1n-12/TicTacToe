#ifndef NPC_H
#define NPC_H

#include <vector>
#include <utility> // For std::pair

class NPC {
public:
    // Method to get NPC's move
    std::pair<int, int> getMove(const std::vector<std::vector<int>>& board);
};

#endif
