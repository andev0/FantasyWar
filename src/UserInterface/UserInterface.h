#ifndef FW_USERINTERFACE_H
#define FW_USERINTERFACE_H

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "UserInterface/TextFormatting/TextFormatter.h"

namespace fw
{
    class UserInterface
    {
    public:
        UserInterface();

        virtual void displayText(const std::string& text) = 0;

        virtual void addTextToQueue(const std::string& text);
        virtual void displayQueuedText();

        virtual ~UserInterface();

    protected:
        TextFormatter* _textFormatter;

        std::vector<std::string> _textQueue;

    };
}

#endif //FW_USERINTERFACE_H
