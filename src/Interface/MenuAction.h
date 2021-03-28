#ifndef FW_MENUACTION_H
#define FW_MENUACTION_H

#include <string>
#include <functional>

namespace fw
{
    class MenuAction
    {
    public:
        MenuAction(std::string actionName, std::string command, 
                   std::function<void()> action);

        std::string getCommand();
        std::string getActionName();

        void executeAction();
    private:
        std::string _command;
        std::string _actionName;
        std::function<void()> _action;
    };
}

#endif //FW_MENUACTION_H