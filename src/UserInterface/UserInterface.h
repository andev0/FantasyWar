#ifndef FW_USERINTERFACE_H
#define FW_USERINTERFACE_H

#include <string>
#include <iostream>

namespace fw
{
    class UserInterface
    {
    public:
        UserInterface();

        virtual void print(std::string text) = 0;

    };
}

#endif //FW_USERINTERFACE_H