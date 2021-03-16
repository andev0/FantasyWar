#include <iostream>
#include <vector>

#include "Console.h"

#include "Interface/GameMenu.h"
#include "Interface/GameMenu/ShopMenu.h"
#include "Interface/GameMenu/UpgradeMenu.h"
#include "Interface/ExtraMenu/LoginMenu.h"

#include "Filesystem/Filesystem.h"
#include "FilesIO/Languages.h"

int main(int argc, char** argv)
{
	fw::Filesystem::setGamePath(argv[0]);
	fw::Translations::changeLanguage("English");

	std::vector<fw::GameMenu*> menus;

	menus.push_back(new fw::ShopMenu("0", "Shop"));
	menus.push_back(new fw::UpgradeMenu("1", "Upgrade menu"));

	std::vector<std::string> menuItems;

	for (size_t i = 0; i < menus.size(); i++)
	{
		menuItems.push_back(menus[i]->getName());
	}

	std::string inputKey = fw::Console::dialog("> Main menu <", menuItems);

	for (size_t i = 0; i < menus.size(); i++)
	{
		if (menus[i]->getKey() == inputKey)
		{
			menus[i]->Show();
		}
	}

	fw::Console::pause("Press Enter to exit.");

	return 0;
}
