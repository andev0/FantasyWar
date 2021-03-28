#include <iostream>
#include <vector>

#include "Console.h"

#include "Interface/GameMenu.h"
#include "Interface/GameMenu/ShopMenu.h"
#include "Interface/GameMenu/UpgradeMenu.h"
#include "Interface/GameMenu/MobArena.h"
#include "Interface/ExtraMenu/LoginMenu.h"

#include "Filesystem/Filesystem.h"
#include "FilesIO/Translations.h"

#include "Extensions/Aliases.h"

#include "Game/Player.h"

using namespace fw;

int main(int argc, char** argv)
{
    Filesystem::setGamePath(argv[0]);
    Translations::changeLanguage("Russian");

    Player player("Gamer", 5, 100);

    std::vector<GameMenu*> menus;

    menus.push_back(new ShopMenu("1", "Shop"));
    menus.push_back(new UpgradeMenu("2", "Upgrade menu"));
    menus.push_back(new MobArena("3", "Mob arena"));

    std::vector<std::string> menuItems;

    menuItems.push_back("Exit");

    for (size_t i = 0; i < menus.size(); i++)
    {
        menuItems.push_back(menus[i]->getName());
    }

    while(true)
    {
        Console::clear();

        std::string inputKey = Console::dialog(makeTitle("Main menu"), 
                                               menuItems);

        if (inputKey == "0")
        {
            break;
        }

        for (size_t i = 0; i < menus.size(); i++)
        {
            if (menus[i]->getKey() == inputKey)
            {
                menus[i]->show(player);
            }
        }
    }

    Console::clear();
    Console::pause(translate("Press Enter to exit."));
    Console::clear();

    return 0;
}
