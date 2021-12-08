#include "Game.h"

namespace fw
{
    void Game::start() 
    {
        #ifdef WINDOWS
            _userInterface = new WindowsConsole();
        #elif LINUX
            _userInterface = new LinuxTerminal();
        #elif TELEGRAM
            _userInterface = new TelegramBot();
        #else
            #error Unknown platform specified in build arguments.
        #endif //OS TYPE

        _userInterface->print("UI print\n");

        delete _userInterface;
    }
}