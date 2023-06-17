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

void Terminal::display(const MenuItem* menuItem)
{
    if (menuItem == nullptr)
    {
        return;
    }

    if (dynamic_cast<const TitleMenuItem*>(menuItem) != nullptr)
    {
        printLine(menuItem->getText());
        printLine();
    }
    else
    {
        printLine(menuItem->getText());
    }
}

} // namespace fw
