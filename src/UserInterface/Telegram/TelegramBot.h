#ifdef TELEGRAM
#ifndef FW_TELEGRAMBOT_H
#define FW_TELEGRAMBOT_H

#include "UserInterface/UserInterface.h"

#include "UserInterface/TextFormatting/Formatters/TelegramTextFormatter.h"

namespace fw
{
    class TelegramBot : public UserInterface
    {
    public:
        TelegramBot();
        
        void displayText(const std::string& text) override;

        void displayQueuedText() override;

    };
}

#endif //FW_TELEGRAMBOT_H
#endif //TELEGRAM
