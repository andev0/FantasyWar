#include "ShopMenu.h"

ShopMenu::ShopMenu(std::string key, std::string name) : GameMenu(key, name)
{

}

void ShopMenu::Show()
{
	std::cout << "SHOP!\n";
}
