#include "ShopMenu.h"

fw::ShopMenu::ShopMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void fw::ShopMenu::Show()
{
	fw::Console::print("SHOP!");
}
