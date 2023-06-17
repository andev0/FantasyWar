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

std::string Terminal::readLine()
{
    std::string input;

    std::getline(std::cin, input);

    return input;
}

} // namespace fw
