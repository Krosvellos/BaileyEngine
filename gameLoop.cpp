#include "gameLoop.h"

GameLoop::GameLoop(std::string mapId, PlayerCharacter* p, Board* pg): activeMapId(mapId), player(p), playground(pg) {}

void GameLoop::runGameLoop(){
    setStatus('A');
    while(status == 'A' || status == 'P') {
        if (status == 'A') {
            playground->render();
            playground->display();
        }
        char inputKey;
        std::cin >> inputKey;
        bool lastKeyIsForGame = false;
        switch(inputKey){
            case 'p':
                if(status == 'A'){
                    // set status to Pause
                    std::cout << "Pausing Game!" << std::endl;
                    setStatus('P');
                } else if (status == 'P') {
                    // set status to Active
                    std::cout << "Resuming Game!" << std::endl;
                    setStatus('A');
                }
                break;
            case 'w':
            case 'a':
            case 's':
            case 'd':
                if(status == 'A'){
                    lastKeyIsForGame = true;
                } else {
                    std::cout << "The game is paused! You cannot move." << std::endl;
                }
                break;
            case 'l':
                std::cout << "Exiting Game loop!" << std::endl;
                setStatus('X');
                break;
            default:
                break;
        }

        if(!lastKeyIsForGame) {
            continue;
        }

        Position newPosition = player->getPosition();
        bool canPlayerGoThere;

        switch(inputKey) {
            case 'w' :
                newPosition.y = newPosition.y - 1;
                canPlayerGoThere = playground->isWalkable(newPosition);
                if(canPlayerGoThere) {
                    player->setPosition(newPosition);
                }

                break;
            case 'a' :
                newPosition.x = newPosition.x - 1;
                canPlayerGoThere = playground->isWalkable(newPosition);
                if(canPlayerGoThere) {
                    player->setPosition(newPosition);
                }
                break;
            case 's' :
                newPosition.y = newPosition.y + 1;
                canPlayerGoThere = playground->isWalkable(newPosition);
                if(canPlayerGoThere) {
                    player->setPosition(newPosition);
                }
                break;
            case 'd' :
                newPosition.x = newPosition.x + 1;
                canPlayerGoThere = playground->isWalkable(newPosition);
                if(canPlayerGoThere) {
                    player->setPosition(newPosition);
                }
                break;
        }
    }
}

void GameLoop::setStatus(char statusChar){
        status = statusChar;
    }