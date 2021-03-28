#ifndef FW_GAMEMENU_H
#define FW_GAMEMENU_H

#include <string>

#include "Game/Player.h"

namespace fw
{
    class GameMenu
    {
    public:
        GameMenu(std::string key, std::string name);

        virtual void show(Player& player) = 0;

        std::string getKey();
        std::string getName();
    private:
        std::string _key;
        std::string _name;
    };
}

#endif // !FW_GAMEMENU_H
