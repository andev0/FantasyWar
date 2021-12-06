#ifdef LINUX

#include "LinuxTerminalUI.h"

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