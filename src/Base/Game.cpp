#include "Game.h"

namespace fw
{
    void Game::start() 
    {
        #ifdef WINDOWS
            _userInterface = new WindowsConsoleUI();
        #elif LINUX
            _userInterface = new LinuxTerminalUI();
        #elif TELEGRAM
            _userInterface = new TelegramBotUI();
        #else
            #error Unknown platform specified in build arguments.
        #endif //OS TYPE

        _userInterface->print("UI print\n");
    }
}