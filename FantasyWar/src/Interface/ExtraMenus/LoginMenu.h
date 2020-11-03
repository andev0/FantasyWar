#pragma once

#ifndef LOGIN_MENU_H
#define LOGIN_MENU_H

#include "../../IOutputable.h"
#include "../../Console.h"

#include <fstream>

class LoginMenu : public IOutputable
{
public:
	void Show() override;
};

#endif // LOGIN_MENU_H
