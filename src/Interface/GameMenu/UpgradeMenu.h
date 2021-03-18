#ifndef FW_UPGRADE_MENU_H
#define FW_UPGRADE_MENU_H

#include <string>

#include "Interface/GameMenu.h"
#include "Console.h"

namespace fw
{
    class UpgradeMenu : public GameMenu
    {
    public:
        UpgradeMenu(std::string key, std::string name);

        void Show(Player& player) override;
    };
}

#endif // !FW_UPGRADE_MENU_H
