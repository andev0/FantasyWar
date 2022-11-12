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
    /// Displays @param text and prompts to press Enter to continue.
    virtual void display(const std::string& text) const override;

    virtual std::string getTextInput() const override;

protected:
    virtual void print(std::string text) const;
    /// Prints @param text followed by std::endl.
    virtual void printLine(std::string text = "") const;
};
} // namespace fw

#endif // FW_LinuxTerminal_H
