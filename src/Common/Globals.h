#ifndef FW_GLOBALS_H
#define FW_GLOBALS_H

#include "Menus/MainMenu.h"
#include "UserInterface/LinuxTerminal.h"

namespace fw
{
const MainMenu g_mainMenu = MainMenu();
const LinuxTerminal g_ui = LinuxTerminal();
} // namespace fw

#endif // FW_GLOBALS_H
