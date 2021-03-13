#include "GameMenu.h"

fw::GameMenu::GameMenu(std::string key, std::string name)
{
	_key = key;
	_name = name;
}

std::string fw::GameMenu::getKey()
{
	return _key;
}

std::string fw::GameMenu::getName()
{
	return _name;
}
