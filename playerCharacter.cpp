#include "playerCharacter.h"

PlayerCharacter::PlayerCharacter(std::string name, short level) : Entity(name, level) { 
    }


void PlayerCharacter::dance() {
    std::cout << pr_name << " dances." << std::endl;
}

