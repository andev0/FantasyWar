#include "Game.h"

#include "UserInterface/TextFormatting/Formatters/CliTextFormatter.h"
#include "UserInterface/TextFormatting/Formatters/TelegramTextFormatter.h"

namespace fw
{
    Game::Game() 
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
    }

    Game::~Game() 
    {
        delete _userInterface;
    }

    void Game::start() 
    {
        CliTextFormatter cliTextFormatter;
        TelegramTextFormatter telegramTextFormatter;

        _userInterface->displayText(
            "<red>This is red <yellow>and yellow</yellow> text</red>! <green>Some green in addition.</green>\n"
        );

        _userInterface->addTextToQueue("<red>This is red <yellow>and yellow</yellow> text</red>! ");
        _userInterface->addTextToQueue("<green>Some green in addition.</green>\n");
        _userInterface->displayQueuedText();

        _userInterface->addTextToQueue("Hello world!\n");
        _userInterface->displayQueuedText();
    }
}
