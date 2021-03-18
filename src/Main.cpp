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

#include "Game/Player.h"

int main(int argc, char** argv)
{
    fw::Filesystem::setGamePath(argv[0]);
    fw::Translations::changeLanguage("Russian");

    fw::Player player("Gamer", 10, 10);

    std::vector<fw::GameMenu*> menus;

    menus.push_back(new fw::ShopMenu("1", "Shop"));
    menus.push_back(new fw::UpgradeMenu("2", "Upgrade menu"));
    menus.push_back(new fw::MobArena("3", "Mob arena"));

    std::vector<std::string> menuItems;

    for (size_t i = 0; i < menus.size(); i++)
    {
        menuItems.push_back(menus[i]->getName());
    }
    menuItems.insert(menuItems.begin(), "Exit");

    while(true)
    {
        fw::Console::clear();

        std::string inputKey = fw::Console::dialog("> " + fw::Translations::translate("Main menu") + " <", menuItems);

        if (inputKey == "0")
        {
            break;
        }

        for (size_t i = 0; i < menus.size(); i++)
        {
            if (menus[i]->getKey() == inputKey)
            {
                menus[i]->Show(player);
            }
        }
    }

    fw::Console::clear();
    fw::Console::pause(fw::Translations::translate("Press Enter to exit."));
    fw::Console::clear();

    return 0;
}
