#include "UpgradeMenu.h"

UpgradeMenu::UpgradeMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void UpgradeMenu::Show()
{
	Console::printMessage("UPGRADE MENU!");
}
