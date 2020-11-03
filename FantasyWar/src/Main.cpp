#include "Interface/GameMenu.h"
#include "Interface/GameMenus/ShopMenu.h"
#include "Interface/GameMenus/UpgradeMenu.h"

#include "Encoder.h"
#include "FilesIO/Languages.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<GameMenu*> menus;

	menus.push_back(new ShopMenu("1", "Shop"));
	menus.push_back(new UpgradeMenu("2", "Upgrade menu"));

	for (size_t i = 0; i < menus.size(); i++)
	{
		cout << menus[i]->getKey() + " - " + menus[i]->getName() + "\n";
	}
	cout << "\n";

	string inputKey = "";
	cin >> inputKey;

	for (size_t i = 0; i < menus.size(); i++)
	{
		if (menus[i]->getKey() == inputKey)
		{
			menus[i]->Show();
		}
	}

	cin.get();

	return 0;
}
