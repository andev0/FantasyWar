#pragma once

#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

class Console
{
public:
	static std::string dialogMessage(std::string message, std::vector<std::string> alternatives = {});
	static void clearConsole();
};

#endif // CONSOLE_H
