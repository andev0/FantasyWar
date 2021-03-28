#include "Dialog.h"

#include "Extensions/Aliases.h"

using namespace fw;

Dialog::Dialog(std::string title, std::vector<MenuAction> actions) 
{
    _title = title;
    _actions = actions;

    for (size_t i = 0; i < _actions.size(); ++i)
    {
        _commandsNames.push_back(_actions[i].getActionName());
    }
}

void Dialog::show() 
{
    std::string commandInput = 
            Console::dialog(_title, _commandsNames);

    for (size_t i = 0; i < _actions.size(); ++i)
    {
        if (commandInput == _actions[i].getCommand())
        {
            _actions[i].executeAction();
            break;
        }
    }
}
