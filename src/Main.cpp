#include <iostream>
#include <vector>

#include "Console.h"

#include "Interface/GameMenu.h"
#include "Interface/GameMenu/ShopMenu.h"
#include "Interface/GameMenu/UpgradeMenu.h"
#include "Interface/ExtraMenu/LoginMenu.h"

#include "FilesIO/Languages.h"

using namespace std;
using namespace fw;

int main(int argc, char** argv)
{
	Languages::changeLanguage("Russian");

	vector<GameMenu*> menus;

	menus.push_back(new ShopMenu("0", "Shop"));
	menus.push_back(new UpgradeMenu("1", "Upgrade menu"));

	vector<std::string> menuItems;

	for (size_t i = 0; i < menus.size(); i++)
	{
		menuItems.push_back(menus[i]->getName());
	}

	string inputKey = Console::dialogMessage("> Main menu <", menuItems);

	for (size_t i = 0; i < menus.size(); i++)
	{
		if (menus[i]->getKey() == inputKey)
		{
			menus[i]->Show();
		}
	}

	Console::pause("Press Enter to exit.");

	return 0;
}
