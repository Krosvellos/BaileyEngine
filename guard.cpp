#include "guard.h"
#include <iostream>

    Guard::Guard(std::string name, short level) : Npc(name,level) {
        pr_type = "guard";
    }
    void Guard::greet() const {
        std::cout << pr_name << " greets you." << std::endl;
    }
       

