#ifndef SHOP_MENU_H
#define SHOP_MENU_H

#include <string>

#include "Interface/GameMenu.h"
#include "Console.h"

namespace fw
{
	class ShopMenu : public GameMenu
	{
	public:
		ShopMenu(std::string key, std::string name);

		void Show() override;
	};
}

#endif // SHOP_MENU_H
