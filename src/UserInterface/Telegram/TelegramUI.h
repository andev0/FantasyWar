#ifdef TELEGRAM
#ifndef FW_TELEGRAMUI_H
#define FW_TELEGRAMUI_H

#include "UserInterface/UserInterface.h"

namespace fw
{
    class TelegramUI : public UserInterface
    {
    public:
        TelegramUI();
        
        void print(std::string text) override;

    };
}

#endif //FW_TELEGRAMUI_H
#endif //TELEGRAM