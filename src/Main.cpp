#include <iostream>
#include <vector>

#include "Console.h"

#include "Interface/GameMenu.h"
#include "Interface/GameMenu/ShopMenu.h"
#include "Interface/GameMenu/UpgradeMenu.h"
#include "Interface/ExtraMenu/LoginMenu.h"

#include "Filesystem/Filesystem.h"
#include "FilesIO/Languages.h"

#include "Game/Player.h"

int main(int argc, char** argv)
{
	fw::Filesystem::setGamePath(argv[0]);
	fw::Translations::changeLanguage("Russian");

	/* std::vector<fw::GameMenu*> menus;

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
	} */

	fw::Entity enemy("Q/A", 9999, 12, 100);
	fw::Player player("FejAleX", 14, 150);

	fw::Console::print(player.getName() + "\t[" + std::to_string(player.getHealth()) + "]");
	fw::Console::print(enemy.getName() + "\t[" + std::to_string(enemy.getHealth()) + "]");

	fw::Console::print(player.getName() + " " + fw::Translations::translate("attacks") + " " + enemy.getName());
	player.attack(&enemy);

	fw::Console::print(player.getName() + "\t[" + std::to_string(player.getHealth()) + "]");
	fw::Console::print(enemy.getName() + "\t[" + std::to_string(enemy.getHealth()) + "]");

	fw::Console::print(enemy.getName() + " " + fw::Translations::translate("attacks") + " " + player.getName());
	enemy.attack(&player);

	fw::Console::print(player.getName() + "\t[" + std::to_string(player.getHealth()) + "]");
	fw::Console::print(enemy.getName() + "\t[" + std::to_string(enemy.getHealth()) + "]");

	/////////////////////////////////////

	fw::Console::pause(fw::Translations::translate("Press Enter to exit."));

	return 0;
}
