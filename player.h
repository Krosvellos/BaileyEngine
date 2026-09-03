#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {

    public:
        Player(std::string name);
        void setPlayerName(std::string name);
        std::string getPlayerName() const;

    private:
        std::string p_playerName;

};

#endif 