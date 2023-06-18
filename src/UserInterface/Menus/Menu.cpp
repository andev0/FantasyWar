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

} // namespace fw
