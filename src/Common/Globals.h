#ifndef FW_GLOBALS_H
#define FW_GLOBALS_H

#include "Menus/MainMenu.h"
#include "UserInterface/LinuxTerminal.h"

namespace fw
{
extern const std::shared_ptr<UserInterface> g_ui;
extern const MainMenu g_mainMenu;
} // namespace fw

#endif // FW_GLOBALS_H
