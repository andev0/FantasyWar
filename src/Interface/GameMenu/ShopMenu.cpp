#include "ShopMenu.h"

#include "Extensions/Aliases.h"

fw::ShopMenu::ShopMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void fw::ShopMenu::show(Player& player)
{
    fw::Console::clear();
    fw::Console::printLine(translate("SHOP!"));
    fw::Console::printLine();
    fw::Console::pause(translate("Press Enter to continue."));
}
