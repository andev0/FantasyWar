#ifndef FW_DIALOG_H
#define FW_DIALOG_H

#include <string>
#include <vector>

#include "Interface/MenuAction.h"

#include "Console.h"

namespace fw
{
    class Dialog
    {
    public:
        Dialog(std::string title, std::vector<MenuAction> actions);

        void show();
    
    private:
        std::string _title;

        std::vector<MenuAction> _actions;

        std::vector<std::string> _commandsNames;

    };
}

#endif //FW_DIALOG_H