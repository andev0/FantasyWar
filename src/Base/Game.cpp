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
                    {"red", "\e[31m"}, {"yellow", "\e[33m"}
                }));

        _userInterface->displayText(
                TextFormatter::formatText("Some text with <bold>bold <italic>and bold italic</italic></bold> symbols!\n", {
                    {"bold", "**", "**"}, {"italic", "__", "__"}
            }));

        delete _userInterface;
    }
}