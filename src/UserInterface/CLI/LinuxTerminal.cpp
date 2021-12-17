#ifdef LINUX

#include "LinuxTerminal.h"

namespace fw
{
    LinuxTerminal::LinuxTerminal() 
    {
        
    }
    
    void LinuxTerminal::displayText(std::string text) 
    {
        fmt::print(text);
    }
}

#endif //LINUX
