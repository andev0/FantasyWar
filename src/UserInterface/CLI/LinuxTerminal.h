#ifdef LINUX
#ifndef FW_LINUXTERMINALUI_H
#define FW_LINUXTERMINALUI_H

#include "UserInterface/UserInterface.h"

#include <string>

#include <fmt/format.h>
#include <fmt/color.h>

namespace fw
{
    class LinuxTerminalUI : public UserInterface
    {
    public:
        LinuxTerminalUI();

        void print(std::string text) override;

    };
}

#endif //FW_LINUXTERMINALUI_H
#endif //LINUX