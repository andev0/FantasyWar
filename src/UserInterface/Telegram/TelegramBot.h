#ifdef TELEGRAM
#ifndef FW_TELEGRAMBOTUI_H
#define FW_TELEGRAMBOTUI_H

#include "UserInterface/UserInterface.h"

namespace fw
{
    class TelegramBotUI : public UserInterface
    {
    public:
        TelegramBotUI();
        
        void print(std::string text) override;

    };
}

#endif //FW_TELEGRAMBOTUI_H
#endif //TELEGRAM