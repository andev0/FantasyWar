#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/MainMenu.h"

#include "UserInterface/Formatter.h"

int main()
{
    fw::Formatter fmt;

    fw::Terminal::printLine(
        fmt.applyColor("I'm blue, da ba dee da ba di", fw::Formatter::BrightColor::BLUE));

    fw::Terminal::display(&fw::MainMenu::getInstance());

    return 0;
}
