#include "UserInterface/Terminal.h"
#include "UserInterface/MenuItems/TitleMenuItem.h"

int main()
{
    fw::TitleMenuItem defaultTitleItem;
    fw::TitleMenuItem titleItem("Fantasy War");
    fw::TextMenuItem textItem("Hello world!");
    fw::InputMenuItem inputItem;

    fw::Terminal::display(&defaultTitleItem);
    fw::Terminal::display(&titleItem);
    fw::Terminal::display(&textItem);
    fw::Terminal::display(&inputItem);
    fw::Terminal::printLine(std::string("You wrote: \"") + inputItem.getResult() + "\"");

    return 0;
}
