#ifndef BOARD_H
#define BOARD_H
#include "playerCharacter.h"
#include "npc.h"
#include "common.h"
#include <vector>

class Board {

    private:
        int boardSizeX = 100;
        int boardSizeY = 100;
        PlayerCharacter* player;
        std::vector<Npc*> enemies;
        std::vector<CellType> map;
        mutable std::vector<char> displayBuffer;
        
    public:
        Board(int sizeX, int sizeY, PlayerCharacter* p, std::vector<CellType> newMap);
        void setEnemies(std::vector<Npc*> enemyList);
        void render() const;
        void generateBorder();
        void display() const;
        bool isWalkable(Position target) const;
        
};

#endif