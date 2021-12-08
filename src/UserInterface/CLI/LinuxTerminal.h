#ifdef LINUX
#ifndef FW_LINUXTERMINAL_H
#define FW_LINUXTERMINAL_H

#include "UserInterface/UserInterface.h"

#include <string>

#include <fmt/format.h>
#include <fmt/color.h>

namespace fw
{
    class LinuxTerminal : public UserInterface
    {
    public:
        LinuxTerminal();

        void print(std::string text) override;

    };
}

#endif //FW_LINUXTERMINAL_H
#endif //LINUX