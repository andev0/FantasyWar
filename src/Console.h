#pragma once

#ifndef CONSOLE_H
#define CONSOLE_H

#include "FilesIO/Languages.h"

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

class Console
{
public:
	static void printMessage(std::string message);
	static void debugPrint(std::string message);

	static std::string dialogMessage(std::string message, 
	                                 std::vector<std::string> alternatives = {});

	static void pause(std::string message = "Press Enter to continue.");
	static void clear();
};

#endif // CONSOLE_H
