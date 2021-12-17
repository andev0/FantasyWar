#include "Game.h"

#include "UserInterface/TextFormatting/Formatters/CliTextFormatter.h"
#include "UserInterface/TextFormatting/Formatters/TelegramTextFormatter.h"

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

        CliTextFormatter cliTextFormatter;
        TelegramTextFormatter telegramTextFormatter;

        _userInterface->displayText(cliTextFormatter.format(
            "<red>This is red <yellow>and yellow</yellow></red> text! <green>Some green in addition.</green>\n"
        ));

        _userInterface->displayText(telegramTextFormatter.format(
            "<bold>This is bold <italic>and italic</italic></bold> text! <bold>Some bold in addition.</bold>\n"
        ));

        delete _userInterface;
    }
}