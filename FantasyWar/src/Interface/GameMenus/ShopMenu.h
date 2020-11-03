#pragma once

#ifndef SHOP_MENU_H
#define SHOP_MENU_H

#include <string>

#include "../GameMenu.h"

class ShopMenu : public GameMenu
{
public:
	ShopMenu(std::string key, std::string name);

	void Show() override;
};

#endif // SHOP_MENU_H
