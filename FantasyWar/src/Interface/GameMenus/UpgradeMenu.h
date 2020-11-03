#pragma once

#ifndef UPGRADE_MENU_H
#define UPGRADE_MENU_H

#include "../GameMenu.h"

#include <string>

class UpgradeMenu : public GameMenu
{
public:
	UpgradeMenu(std::string key, std::string name);

	void Show() override;
};

#endif // UPGRADE_MENU_H
