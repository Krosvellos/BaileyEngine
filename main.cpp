#include "playerCharacter.h"
#include "player.h"
#include "guard.h"
#include "board.h"
#include "gameLoop.h"
#include <iostream>

int main() {
    Guard bigGuard("Ted", 5);
    std::cout << "Guard: " << bigGuard.getName() << " has been created" << std::endl;
    bigGuard.greet();

    PlayerCharacter me("Krosyk", 1);
    std::cout << "Player " << me.getName() << " was created." << std::endl;
    std::cout << "Player has Level: " << me.getLevel() << std::endl;
    int width = 50;
    int height = 50;
    std::vector<CellType> grid(width * height, CellType::Floor);
    me.setPosition({15,15});
    Board gameBoard(width, height, &me, grid);
    gameBoard.generateBorder();
    gameBoard.render();
    gameBoard.display();
    GameLoop game("123A", &me, &gameBoard);
    game.runGameLoop();
    
    return 0;
}
