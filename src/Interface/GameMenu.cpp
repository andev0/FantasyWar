#include "GameMenu.h"

GameMenu::GameMenu(std::string key, std::string name)
{
	_key = key;
	_name = name;
}

std::string GameMenu::getKey()
{
	return _key;
}

std::string GameMenu::getName()
{
	return _name;
}
