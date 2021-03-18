#include "UpgradeMenu.h"

fw::UpgradeMenu::UpgradeMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void fw::UpgradeMenu::Show(Player& player)
{
    Console::print("UPGRADE MENU!");
}
