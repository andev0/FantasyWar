#ifdef WINDOWS
#ifndef FW_WINDOWSCONSOLE_H
#define FW_WINDOWSCONSOLE_H

#include "UserInterface/UserInterface.h"

namespace fw
{
    class WindowsConsole : public UserInterface
    {
    public:
        WindowsConsole();
        
        void displayText(const std::string& text) override;
    
    };
}

#endif //FW_WINDOWSCONSOLE_H
#endif //WINDOWS
