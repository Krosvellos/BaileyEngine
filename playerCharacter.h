#ifndef PLAYERCHARACTER_H 
#define PLAYERCHARACTER_H

#include "common.h"
#include <string> 
#include <iostream> 
#include "entity.h"

class PlayerCharacter : public Entity {

    public:
        PlayerCharacter(std::string name, short level);
        void dance();
        
};

#endif