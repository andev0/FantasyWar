#include "ShopMenu.h"

ShopMenu::ShopMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void ShopMenu::Show()
{
	Console::printMessage("SHOP!");
}
