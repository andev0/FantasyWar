#include "LinuxTerminal.h"

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/OptionsListMenuItem.h"
#include "MenuItems/InputMenuItem.h"

namespace fw
{
void LinuxTerminal::display(const MenuItem* menuItem) const
{
    if (auto inputItem = dynamic_cast<const InputMenuItem*>(menuItem))
    {
        print("> ");
        const std::string& input = getTextInput();
        printLine();
        inputItem->processInput(input);
    }
    else if (auto optionsListItem = dynamic_cast<const OptionsListMenuItem*>(menuItem))
    {
        const auto& options = optionsListItem->getOptions();

        for (size_t i = 0; i < options.size(); ++i)
        {
            printLine(STRING(i << ". " << options[i]->getText()));
        }
        printLine();
    }
    else if (auto titleItem = dynamic_cast<const TitleMenuItem*>(menuItem))
    {
        printLine(STRING("[ " << titleItem->getTitle() << " ]\n"));
    }
    else if (auto textItem = dynamic_cast<const TextMenuItem*>(menuItem))
    {
        printLine(textItem->getText());
    }
    else
    {
        printLine("-- The element can't be displayed --");
    }
}

void LinuxTerminal::display(const std::string& text) const
{
    printLine(text);
    printLine("\nPress Enter to continue.");
    getTextInput();
}

std::string LinuxTerminal::getTextInput() const
{
    std::string input;
    std::getline(std::cin, input);

    return input;
}

void LinuxTerminal::print(std::string text) const
{
    std::cout << text << std::flush;
}

void LinuxTerminal::printLine(std::string text) const
{
    std::cout << text << std::endl;
}

} // namespace fw
