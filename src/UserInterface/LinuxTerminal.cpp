#include "LinuxTerminal.h"

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/OptionsListMenuItem.h"

namespace fw
{
void LinuxTerminal::display(const MenuItem* menuItem) const
{
    if (const OptionsListMenuItem* optionsListItem
        = dynamic_cast<const OptionsListMenuItem*>(menuItem))
    {
        for (size_t i = 0; i < optionsListItem->getOptions().size(); ++i)
        {
            display(
                STRING((i + 1) << ". " << optionsListItem->getOptions()[i]->getText()));
        }
        display("");
    }
    else if (const TitleMenuItem* titleItem
             = dynamic_cast<const TitleMenuItem*>(menuItem))
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
    else
    {
        display("-- The element can't be displayed --");
    }
}

void LinuxTerminal::display(const std::string& text) const
{
    std::cout << text << std::endl;
}

} // namespace fw
