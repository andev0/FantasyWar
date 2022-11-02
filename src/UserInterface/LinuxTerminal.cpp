#include "LinuxTerminal.h"

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/OptionsListMenuItem.h"

namespace fw
{
void LinuxTerminal::display(const MenuItem* menuItem) const
{
    if (auto optionsListItem = dynamic_cast<const OptionsListMenuItem*>(menuItem))
    {
        const auto& options = optionsListItem->getOptions();

        for (size_t i = 0; i < options.size(); ++i)
        {
            display(STRING((i + 1) << ". " << options[i]->getText()));
        }
        display("");
    }
    else if (auto titleItem = dynamic_cast<const TitleMenuItem*>(menuItem))
    {
        display(STRING("[ " << titleItem->getTitle() << " ]\n"));
    }
    else if (auto textItem = dynamic_cast<const TextMenuItem*>(menuItem))
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
