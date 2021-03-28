#include "UpgradeMenu.h"

#include "Extensions/Aliases.h"

fw::UpgradeMenu::UpgradeMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void fw::UpgradeMenu::show(Player& player)
{
    fw::Console::clear();
    fw::Console::printLine(translate("UPGRADE MENU!"));
    fw::Console::printLine();
    fw::Console::pause(translate("Press Enter to continue."));
}
