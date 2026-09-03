#ifndef NPC_H
#define NPC_H

#include "common.h"
#include <string>
#include "entity.h"

class Npc : public Entity {

    public: 
        Npc(std::string name, short level);
        
};

#endif
