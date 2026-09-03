#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "board.h"
#include <string>
class GameLoop {

    private:
        char status;
        std::string activeMapId;
        PlayerCharacter* player;
        std::vector<Npc*> enemies;
        
    protected: 
        Board* playground;

    public:
        GameLoop(std::string mapId, PlayerCharacter* p, Board* pg);
        void setStatus(char statusChar);
        void runGameLoop();

};

#endif