#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/LoginMenu.h"

#include "Game/Player.h"

int main()
{
    fw::Terminal::display(&fw::LoginMenu::getInstance());

    return 0;
}
