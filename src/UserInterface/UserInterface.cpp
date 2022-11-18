#include "UserInterface.h"

namespace fw
{

void UserInterface::mainLoop() const
{
    while (m_menuStack.size() > 0)
    {
        display();
    }
}

void UserInterface::display() const
{
    display(m_menuStack.top());
}

void UserInterface::display(const Menu* menu) const
{
    for (const auto& menuItem : menu->getMenuItems())
    {
        display(menuItem.get());
    }
}

void UserInterface::pushMenu(const Menu* menu)
{
    m_menuStack.push(menu);
}

void UserInterface::popMenu()
{
    if (m_menuStack.size() > 0)
    {
        m_menuStack.pop();
    }
}

UserInterface::~UserInterface() { }
} // namespace fw
