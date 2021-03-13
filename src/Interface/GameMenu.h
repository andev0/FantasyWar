#pragma once

#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <string>

class GameMenu
{
public:
	GameMenu(std::string key, std::string name);

	virtual void Show() = 0;

	std::string getKey();
	std::string getName();
private:
	std::string _key;
	std::string _name;
};

#endif // GAMEMENU_H
