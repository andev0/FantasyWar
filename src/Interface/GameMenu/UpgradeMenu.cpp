#include "UpgradeMenu.h"

fw::UpgradeMenu::UpgradeMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void fw::UpgradeMenu::Show()
{
	Console::print("UPGRADE MENU!");
}
