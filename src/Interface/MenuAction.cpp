#include "MenuAction.h"

using namespace fw;

MenuAction::MenuAction(std::string actionName, std::string command, 
                       std::function<void()> action)
{
    _actionName = actionName;
    _command = command;
    _action = action;
}

std::string MenuAction::getCommand() 
{
    return _command;
}

std::string MenuAction::getActionName() 
{
    return _actionName;
}

void MenuAction::executeAction() 
{
    _action();
}
