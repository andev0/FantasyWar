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
        fmt::print(_textFormatter->format(text));
    }

    LinuxTerminal::~LinuxTerminal()
    {
        
    }
}

#endif //LINUX
