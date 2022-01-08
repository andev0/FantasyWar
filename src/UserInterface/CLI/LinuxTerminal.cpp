#ifdef LINUX

#include "LinuxTerminal.h"

namespace fw
{
    LinuxTerminal::LinuxTerminal() 
    {
        _textFormatter = new CliTextFormatter();
    }
    
    void LinuxTerminal::displayText(const std::string& text) 
    {
        fmt::print(_textFormatter->format(text));
    }

    LinuxTerminal::~LinuxTerminal()
    {
        delete _textFormatter;
    }
}

#endif //LINUX
