#ifndef FW_MENU_H
#define FW_MENU_H

#include "Common/Includes.h"

#include "MenuItems/MenuItem.h"

namespace fw
{
class Menu
{
public:
    virtual ~Menu() = 0;

    virtual const std::vector<std::shared_ptr<MenuItem>>& getMenuItems() const
    {
        return m_menuItems;
    }

protected:
    std::vector<std::shared_ptr<MenuItem>> m_menuItems;
};
} // namespace fw

#endif // FW_MENU_H