#include <iostream>

#include "Common/Globals.h"

int main()
{
    fw::g_ui->pushMenu(&fw::g_mainMenu);

    fw::g_ui->mainLoop();

    return 0;
}
