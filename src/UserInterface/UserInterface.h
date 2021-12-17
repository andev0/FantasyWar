#ifndef FW_USERINTERFACE_H
#define FW_USERINTERFACE_H

#include <string>
#include <iostream>
#include <map>

#include "UserInterface/TextFormatting/TextFormatter.h"

namespace fw
{
    class UserInterface
    {
    public:
        UserInterface();

        virtual void displayText(std::string text) = 0;

        virtual ~UserInterface();

    protected:
        TextFormatter* _textFormatter;

    };
}

#endif //FW_USERINTERFACE_H
