#ifndef FW_USERINTERFACE_H
#define FW_USERINTERFACE_H

#include <string>
#include <iostream>
#include <map>

namespace fw
{
    class UserInterface
    {
    public:
        UserInterface();

        virtual void displayText(std::string text) = 0;

        virtual ~UserInterface();

    };
}

#endif //FW_USERINTERFACE_H