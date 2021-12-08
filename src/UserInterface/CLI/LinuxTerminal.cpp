#ifdef LINUX

#include "LinuxTerminal.h"

namespace fw
{
    LinuxTerminalUI::LinuxTerminalUI() 
    {
        
    }
    
    void LinuxTerminalUI::print(std::string text) 
    {
        fmt::print(text);
    }
}

#endif //LINUX