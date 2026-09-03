#include "player.h"

Player::Player(std::string name) : p_playerName(name) {}
std::string Player::getPlayerName() const {
    return p_playerName;
}
void Player::setPlayerName(std::string name) {
    p_playerName = name;
}


