#include "UpgradeMenu.h"

UpgradeMenu::UpgradeMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void UpgradeMenu::Show()
{
	std::cout << "UPGRADE MENU!\n";
}
