#ifndef FW_USERINTERFACE_H
#define FW_USERINTERFACE_H

#include "Common/Includes.h"

#include "Menus/Menu.h"
#include "MenuItems/MenuItem.h"

namespace fw
{
class UserInterface
{
public:
    virtual ~UserInterface() = 0;

    virtual void display(const Menu* menu) const;
    virtual void display(const MenuItem* menuItem) const = 0;
    virtual void display(const std::string& text) const = 0;
};
} // namespace fw

#endif // FW_USERINTERFACE_H