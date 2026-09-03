#include "entity.h"

Entity::Entity(std::string name, short level) : pr_name(name), pr_level(level), pr_position{0, 0}, alive(true) {}

std::string Entity::getName() const {
    return pr_name;
}
void Entity::die() {
    alive = false;
}
void Entity::reviveSelf() {
    alive = true;
}

void Entity::setPosition(Position new_p) {
    pr_position = new_p;
}

Position Entity::getPosition() const {
    return pr_position;
}

short Entity::getLevel() const {
    return pr_level;
}

void Entity::setLevel(short level) {
    pr_level = level;
}
