#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/LoginMenu.h"

#include "Game/Player.h"

int main()
{
    fw::Terminal::pushMenuStack(&fw::LoginMenu::getInstance());

    do
    {
        fw::Terminal::clear();
    } while (fw::Terminal::displayTopmostMenu());

    return 0;
}
