#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "common.h"

class Entity {

    public: 
        Entity(std::string name, short level);
        std::string getName() const; //getter
        void die();
        void reviveSelf();
        void setPosition(Position new_p);
        Position getPosition() const;
        short getLevel() const;
        void setLevel(short level);

    protected:
    Position pr_position;
    short pr_level;
    bool alive;
    std::string pr_name;
    std::string pr_type;

};

#endif