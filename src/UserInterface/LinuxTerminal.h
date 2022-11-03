#ifndef FW_LinuxTerminal_H
#define FW_LinuxTerminal_H

#include "UserInterface.h"

#include "MenuItems/MenuItem.h"

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

    virtual std::string getTextInput() const override;
};
} // namespace fw

#endif // FW_LinuxTerminal_H
