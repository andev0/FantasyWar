#include "Game.h"

#include "UserInterface/TextFormatting/TextFormatter.h"

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

        _userInterface->displayText(
                TextFormatter::formatText("Some text with <red>red <yellow>and yellow</yellow></red> symbols!\n", {
                    { {"red", "\e[31m", ""}, {"yellow", "\e[33m", ""} }
            }));

        delete _userInterface;
    }
}