#include "Game.h"

namespace fw
{
    void Game::start() 
    {
        #ifdef WINDOWS
            _userInterface = new WindowsCmdUI();
        #elif LINUX
            _userInterface = new LinuxTerminalUI();
        #elif TELEGRAM
            _userInterface = new TelegramUI();
        #else
            #error Unknown platform specified in build arguments.
        #endif //OS TYPE

        _userInterface->print("UI print\n");
    }
}