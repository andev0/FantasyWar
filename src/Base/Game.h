#ifndef FW_GAME_H
#define FW_GAME_H

#include "App.h"

#include "UserInterface/UserInterface.h"

#include "UserInterface/CLI/LinuxTerminal.h"
#include "UserInterface/CLI/WindowsConsole.h"
#include "UserInterface/Telegram/TelegramBot.h"

namespace fw
{
    class Game : public App
    {
    public:
        Game();
        ~Game() override;

        void start() override;
        
    private:
        UserInterface* _userInterface;

    };
}

#endif //FW_GAME_H
