#include "board.h"
#include <iostream>
Board::Board(int x, int y, PlayerCharacter* p, std::vector<CellType> newMap) : boardSizeX(x), boardSizeY(y), player(p),
    map(newMap), displayBuffer(x * y) {}

void Board::setEnemies(std::vector<Npc*> enemyList) {
    enemies = enemyList;
}

void Board::generateBorder() {
    for(int y = 0; y <= boardSizeY - 1; y++){
        for(int x = 0; x <= boardSizeX - 1; x++){
            if(y == 0 || x == 0 || y == boardSizeY - 1 || x == boardSizeX - 1 ) {
                map[y * boardSizeX + x] = CellType::Wall;
            }
        }
    }
}

void Board::render() const {
    for(std::vector<CellType>::size_type i = 0; i != map.size(); i++) {
        
        switch(map[i]){
            case CellType::Floor :
                displayBuffer[i] = ' ';
                break;
            case CellType::Wall :
                displayBuffer[i] = '#';
                break;
            case CellType::Exit :
                displayBuffer[i] = 'X';
                break;
            case CellType::Empty :
                displayBuffer[i] = 'O';
                break;
            default:
                break;
            }
    }

    int playerX = player->getPosition().x;
    int playerY = player->getPosition().y;

    if(playerX >= 0 && playerX < boardSizeX && playerY >= 0 && playerY < boardSizeY) {
            std::vector<CellType>::size_type playerIndex = playerY * boardSizeX + playerX;
            displayBuffer[playerIndex] = '@';

    }

}

void Board::display() const {

    for(std::vector<CellType>::size_type i = 0; i != displayBuffer.size(); i++) {
    
        std::cout << displayBuffer[i];

        if((i + 1) % boardSizeX == 0){
            std::cout << '\n';
        } 
    }
}

bool Board::isWalkable(Position target) const {
    // inverse of playerX >= 0 && playerX < boardSizeX && playerY >= 0 && playerY < boardSizeY
    if(target.x < 0 || target.x >= boardSizeX || target.y < 0 || target.y >= boardSizeY){
        return false;
    }

    switch(map[target.y * boardSizeX + target.x]){
        case CellType::Floor: 
            return true;
        case CellType::Exit:  
            return true;
        default:              
            return false;
    }
}
