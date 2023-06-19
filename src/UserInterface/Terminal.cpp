#include "Terminal.h"

namespace fw
{

void Terminal::print(const std::string& text)
{
    std::cout << text;
}

void Terminal::printLine(const std::string& text)
{
    std::cout << text << std::endl;
}

void Terminal::display(MenuItem* menuItem)
{
    if (menuItem == nullptr)
    {
        return;
    }

    using Color = fw::Formatter::BrightColor;

    if (auto inputItem = dynamic_cast<InputMenuItem*>(menuItem))
    {
        print(m_formatter.getColorCode(Color::GREEN));

        print(menuItem->getText());
        inputItem->setResult(readLine());
        printLine();

        print(m_formatter.getResetColorCode());
    }
    else if (dynamic_cast<TitleMenuItem*>(menuItem) != nullptr)
    {
        printLine(m_formatter.applyColor(menuItem->getText(), Color::CYAN));
        printLine();
    }
    else
    {
        printLine(m_formatter.applyColor(menuItem->getText(), Color::WHITE));
    }
}

void Terminal::display(const Menu* menu)
{
    for (const auto& menuItem : menu->getMenuItems())
    {
        display(menuItem.get());
    }

    if (!menu->getMenuOptions().empty())
    {
        printLine();

        for (size_t i = 0; i < menu->getMenuOptions().size(); ++i)
        {
            printLine(m_formatter.applyColor(std::to_string(i) + ". "
                                                 + menu->getMenuOptions()[i].getName(),
                                             fw::Formatter::DarkColor::WHITE));
        }
    }

    InputMenuItem inputItem;

    if (!menu->getMenuOptions().empty() || !menu->getCommands().empty())
    {
        printLine();
        display(&inputItem);
    }

    processInput(menu, inputItem.getResult());
}

void Terminal::displayError(const std::string& text)
{
    printLine(m_formatter.applyColor(text, Formatter::BrightColor::RED));
    printLine(m_formatter.applyColor("Press Enter to continue.",
                                     Formatter::BrightColor::BLACK));
    readLine();
}

std::string Terminal::readLine()
{
    std::string input;

    std::getline(std::cin, input);

    return input;
}

void Terminal::processInput(const Menu* menu, const std::string& input)
{
    assert(!menu->getMenuOptions().empty() || !menu->getCommands().empty());

    if (!menu->getMenuOptions().empty())
    {
        std::smatch match;

        if (std::regex_match(input, match, std::regex("[0-9]+")))
        {
            size_t choosedOption = std::stoi(input);

            if (menu->getMenuOptions().size() > choosedOption)
            {
                menu->getMenuOptions()[choosedOption].execute();
                return;
            }
        }
    }

    if (!menu->getCommands().empty())
    {
        for (const auto& command : menu->getCommands())
        {
            if (command.executeOnMatch(input))
            {
                return;
            }
        }

        displayError(std::string("Unrecognized option \"") + input + "\".");
        return;
    }

    displayError(std::string("Please, enter a number from 0 to ")
                 + std::to_string(menu->getMenuOptions().size()) + ".");
}

} // namespace fw
