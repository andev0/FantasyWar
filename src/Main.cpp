#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/LoginMenu.h"

int main()
{
    fw::Terminal::display(&fw::LoginMenu::getInstance());

    return 0;
}
