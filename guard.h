#ifndef GUARD_H
#define GUARD_H
#include "npc.h"
class Guard : public Npc {

    public:
        Guard(std::string name, short level);
        void greet() const;

};
#endif