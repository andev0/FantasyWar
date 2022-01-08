#ifndef FW_GAME_H
#define FW_GAME_H

#include "precompiled.h"

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
        Game(const Game& other);
        ~Game() override;

        Game& operator=(const Game& other);

        void start() override;
        
    private:
        UserInterface* r_userInterface;

    };
}

#endif //FW_GAME_H
