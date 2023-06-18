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

    if (auto inputItem = dynamic_cast<InputMenuItem*>(menuItem))
    {
        print(menuItem->getText());
        inputItem->setResult(readLine());
        printLine();
    }
    else if (dynamic_cast<TitleMenuItem*>(menuItem) != nullptr)
    {
        printLine(menuItem->getText());
        printLine();
    }
    else
    {
        printLine(menuItem->getText());
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
            printLine(std::to_string(i) + ". " + menu->getMenuOptions()[i].getName());
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
