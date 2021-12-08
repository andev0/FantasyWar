#ifdef WINDOWS
#ifndef FW_WINDOWSCONSOLEUI_H
#define FW_WINDOWSCONSOLEUI_H

#include "UserInterface/UserInterface.h"

namespace fw
{
    class WindowsConsoleUI : public UserInterface
    {
    public:
        WindowsConsoleUI();
        
        void print(std::string text) override;
    
    };
}

#endif //FW_WINDOWSCONSOLEUI_H
#endif //WINDOWS