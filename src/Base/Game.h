#ifndef FW_GAME_H
#define FW_GAME_H

#include "App.h"

#include "UserInterface/UserInterface.h"

#include "UserInterface/Linux/LinuxTerminalUI.h"
#include "UserInterface/Windows/WindowsCmdUI.h"
#include "UserInterface/Telegram/TelegramUI.h"

namespace fw
{
    class Game : public App
    {
    public:
        void start() override;
        
    private:
        UserInterface* _userInterface;

    };
}

#endif //FW_GAME_H