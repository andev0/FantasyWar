#ifdef WINDOWS

#include "WindowsConsole.h"

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#endif

namespace fw
{
    WindowsConsole::WindowsConsole() 
        : UserInterface::UserInterface(new CliTextFormatter())
    {
        SetConsoleCP(65001);

        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
    
    void WindowsConsole::displayText(const std::string& text) 
    {
        
    }
}

#endif //WINDOWS
