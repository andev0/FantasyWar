#pragma once

#ifndef FW_CONSOLE_H
#define FW_CONSOLE_H

#include "FilesIO/Translations.h"

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

namespace fw
{
    class Console
    {
    public:
        static void print(std::string message);
        static void debugPrint(std::string message);

        static std::string dialog(std::string message, 
                                  std::vector<std::string> alternatives = {"Yes", "No"});

        static void pause(std::string message = "Press Enter to continue.");
        static void clear();
    };
}

#endif // !FW_CONSOLE_H
