#ifndef FW_USERINTERFACE_H
#define FW_USERINTERFACE_H

#include "Common/Includes.h"

#include "Menus/Menu.h"

namespace fw
{
class UserInterface
{
public:
    virtual ~UserInterface();

    virtual void mainLoop() const;

    /// Display the last entry from menu stack.
    virtual void display() const;
    /// Display all items in menu consequentially.
    virtual void display(const Menu* menu) const;
    virtual void display(const MenuItem* menuItem) const = 0;
    virtual void display(const std::string& text) const = 0;

    virtual void pushMenu(const Menu* menu);
    /// Pop a menu from menu stack and exit an application if no entries left.
    virtual void popMenu();

    virtual std::string getTextInput() const = 0;

protected:
    std::stack<const Menu*> m_menuStack;
};
} // namespace fw

#endif // FW_USERINTERFACE_H
