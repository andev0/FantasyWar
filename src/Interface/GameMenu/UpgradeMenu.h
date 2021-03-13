#pragma once

#ifndef UPGRADE_MENU_H
#define UPGRADE_MENU_H

#include "Interface/GameMenu.h"
#include "Console.h"

#include <string>

namespace fw
{
	class UpgradeMenu : public GameMenu
	{
	public:
		UpgradeMenu(std::string key, std::string name);

		void Show() override;
	};
}

#endif // UPGRADE_MENU_H
