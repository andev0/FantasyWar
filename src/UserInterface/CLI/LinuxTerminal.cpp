#ifdef LINUX

#include "precompiled.h"

#include "LinuxTerminal.h"

namespace fw
{
    LinuxTerminal::LinuxTerminal() 
        : UserInterface::UserInterface(new CliTextFormatter())
    {
        
    }
    
    void LinuxTerminal::displayText(const std::string& text) 
    {
        fmt::print(r_textFormatter->format(text));
    }

    LinuxTerminal::~LinuxTerminal()
    {
        
    }
}

#endif //LINUX
