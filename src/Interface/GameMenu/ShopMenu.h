#ifndef FW_SHOP_MENU_H
#define FW_SHOP_MENU_H

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

#endif // !FW_SHOP_MENU_H
