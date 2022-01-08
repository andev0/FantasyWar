#ifdef LINUX
#ifndef FW_LINUXTERMINAL_H
#define FW_LINUXTERMINAL_H

#include "UserInterface/UserInterface.h"

#include "UserInterface/TextFormatting/Formatters/CliTextFormatter.h"

namespace fw
{
    class LinuxTerminal : public UserInterface
    {
    public:
        LinuxTerminal();
        ~LinuxTerminal();

        void displayText(const std::string& text) override;

    };
}

#endif //FW_LINUXTERMINAL_H
#endif //LINUX
