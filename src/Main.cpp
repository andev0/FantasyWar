#include "UserInterface/Terminal.h"
#include "UserInterface/MenuItems/TitleMenuItem.h"

int main()
{
    fw::TextMenuItem textItem("Hello world!");
    fw::TitleMenuItem defaultTitleItem;
    fw::TitleMenuItem titleItem("Fantasy War");

    fw::Terminal::printLine(defaultTitleItem.getText());
    fw::Terminal::printLine();
    fw::Terminal::printLine(titleItem.getText());
    fw::Terminal::printLine();
    fw::Terminal::printLine(textItem.getText());

    return 0;
}
