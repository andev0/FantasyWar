#include "Game.h"

#include "UserInterface/TextFormatting/Formatters/CliTextFormatter.h"
#include "UserInterface/TextFormatting/Formatters/TelegramTextFormatter.h"

namespace fw
{
    Game::Game() 
    {
        #ifdef WINDOWS
            r_userInterface = new WindowsConsole();
        #elif LINUX
            r_userInterface = new LinuxTerminal();
        #elif TELEGRAM
            r_userInterface = new TelegramBot();
        #else
            #error Unknown platform specified in build arguments.
        #endif //OS TYPE
    }
    
    Game::Game(const Game& other) 
        : r_userInterface(other.r_userInterface)
    {
        
    }

    Game::~Game() 
    {
        delete r_userInterface;
    }
    
    Game& Game::operator=(const Game& other) 
    {
        if (this == &other)
        {
            return *this;
        }

        r_userInterface = other.r_userInterface;

        return *this;
    }

    void Game::start() 
    {
        CliTextFormatter cliTextFormatter;
        TelegramTextFormatter telegramTextFormatter;

        r_userInterface->displayText(
            "<red>This is red <yellow>and yellow</yellow> text</red>! <green>Some green in addition.</green>\n"
        );

        r_userInterface->addTextToQueue("<red>This is red <yellow>and yellow</yellow> text</red>! ");
        r_userInterface->addTextToQueue("<green>Some green in addition.</green>\n");
        r_userInterface->displayQueuedText();

        r_userInterface->addTextToQueue("Hello world!\n");
        r_userInterface->displayQueuedText();
    }
}
