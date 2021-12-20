#ifdef TELEGRAM

#include "TelegramBot.h"

namespace fw
{
    TelegramBot::TelegramBot() 
    {
        
    }
    
    void TelegramBot::displayText(std::string text) 
    {
        
    }
    
    void TelegramBot::displayQueuedText() 
    {
        std::string message = "";

        for (std::string& text : _textQueue)
        {
            message += text;
        }

        displayText(message);

        _textQueue.clear();
    }
}

#endif //TELEGRAM
