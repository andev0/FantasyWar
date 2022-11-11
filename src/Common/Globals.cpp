#include "Globals.h"

namespace fw
{
const std::shared_ptr<UserInterface> g_ui(new LinuxTerminal());
const MainMenu g_mainMenu;
} // namespace fw
