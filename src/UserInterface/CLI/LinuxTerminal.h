#ifdef LINUX
#ifndef FW_LINUXTERMINAL_H
#define FW_LINUXTERMINAL_H

#include "UserInterface/UserInterface.h"

#include <string>

#include <fmt/format.h>
#include <fmt/color.h>

#include "UserInterface/TextFormatting/Formatters/CliTextFormatter.h"

namespace fw
{
    class LinuxTerminal : public UserInterface
    {
    public:
        LinuxTerminal();
        ~LinuxTerminal();

        void displayText(std::string text) override;

    };
}

#endif //FW_LINUXTERMINAL_H
#endif //LINUX
