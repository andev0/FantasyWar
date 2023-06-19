#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/MainMenu.h"

int main()
{
    while (true)
    {
        system("clear");
        fw::Terminal::display(&fw::MainMenu::getInstance());
    }

    return 0;
}
