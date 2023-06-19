#include "Menu.h"

namespace fw
{

const std::vector<std::unique_ptr<MenuItem>>& Menu::getMenuItems() const
{
    return m_menuItems;
}

const std::vector<Action>& Menu::getMenuOptions() const
{
    return m_actions;
}

const std::vector<Command>& Menu::getCommands() const
{
    return m_commands;
}

void Menu::addMenuItem(std::unique_ptr<MenuItem> menuItem)
{
    m_menuItems.push_back(std::move(menuItem));
}

void Menu::addMenuOption(const Action& menuOption)
{
    m_actions.push_back(menuOption);
}

void Menu::addMenuOption(const std::string& name, const std::function<void()>& action)
{
    m_actions.emplace_back(name, action);
}

void Menu::addCommand(const Command& command)
{
    m_commands.push_back(command);
}

void Menu::addCommand(const std::string& pattern, const std::function<void()>& action)
{
    m_commands.emplace_back(pattern, action);
}

} // namespace fw
