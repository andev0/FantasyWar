#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/MainMenu.h"

int main()
{
    fw::Terminal::display(&fw::MainMenu::getInstance());

    return 0;
}
