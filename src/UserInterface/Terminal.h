#ifndef FW_TERMINAL_H
#define FW_TERMINAL_H

#include <iostream>
#include <string>

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/InputMenuItem.h"

namespace fw
{

class Terminal
{
public:
    static void print(const std::string& text);
    static void printLine(const std::string& text = "");
    static void display(MenuItem* menuItem);

    static std::string readLine();
};

} // namespace fw

#endif // FW_TERMINAL_H
