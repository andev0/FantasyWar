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

        InputMenuItem inputItem;

        printLine();
        display(&inputItem);

        size_t choosedOption = std::stoi(inputItem.getResult());

        if (menu->getMenuOptions().size() > choosedOption)
        {
            menu->getMenuOptions()[choosedOption].execute();
        }
    }
}

std::string Terminal::readLine()
{
    std::string input;

    std::getline(std::cin, input);

    return input;
}

} // namespace fw
