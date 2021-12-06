#ifdef WINDOWS
#ifndef FW_WINDOWSCMDUI_H
#define FW_WINDOWSCMDUI_H

#include "UserInterface/UserInterface.h"

namespace fw
{
    class WindowsCmdUI : public UserInterface
    {
    public:
        WindowsCmdUI();
        
        void print(std::string text) override;
    
    };
}

#endif //FW_WINDOWSCMDUI_H
#endif //WINDOWS