#pragma once

#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "../IOutputable.h"

#include <string>

class GameMenu : IOutputable
{
public:
	GameMenu(std::string key, std::string name);

	virtual void Show() override = 0;

	std::string getKey();
	std::string getName();
private:
	std::string _key;
	std::string _name;
};

#endif // GAMEMENU_H
