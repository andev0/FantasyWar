#ifndef FW_LinuxTerminal_H
#define FW_LinuxTerminal_H

#include "UserInterface.h"

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/OptionMenuItem.h"
#include "MenuItems/TextMenuItem.h"

namespace fw
{
class LinuxTerminal : public UserInterface
{
public:
    LinuxTerminal() { }
    virtual ~LinuxTerminal() { }

    using UserInterface::display;
    virtual void display(const MenuItem* menuItem) const override;
    virtual void display(const std::string& text) const override;
};
} // namespace fw

#endif // FW_LinuxTerminal_H
