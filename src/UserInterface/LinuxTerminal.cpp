#include "LinuxTerminal.h"

namespace fw
{
void LinuxTerminal::display(const MenuItem* menuItem) const
{
    if (const TitleMenuItem* titleItem = dynamic_cast<const TitleMenuItem*>(menuItem))
    {
        display(STRING("[ " << titleItem->getTitle() << " ]\n"));
    }
    else if (const OptionMenuItem* optionItem
             = dynamic_cast<const OptionMenuItem*>(menuItem))
    {
        display(optionItem->getText());
    }
    else if (const TextMenuItem* textItem = dynamic_cast<const TextMenuItem*>(menuItem))
    {
        display(textItem->getText());
    }
}

void LinuxTerminal::display(const std::string& text) const
{
    std::cout << text << std::endl;
}

} // namespace fw
