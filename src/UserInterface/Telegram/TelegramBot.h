#ifdef TELEGRAM
#ifndef FW_TELEGRAMBOT_H
#define FW_TELEGRAMBOT_H

#include "UserInterface/UserInterface.h"

namespace fw
{
    class TelegramBot : public UserInterface
    {
    public:
        TelegramBot();
        
        void print(std::string text) override;

    };
}

#endif //FW_TELEGRAMBOT_H
#endif //TELEGRAM