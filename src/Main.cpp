#include "UserInterface/Terminal.h"
#include "UserInterface/MenuItems/TitleMenuItem.h"

int main()
{
    fw::TitleMenuItem defaultTitleItem;
    fw::TitleMenuItem titleItem("Fantasy War");
    fw::TextMenuItem textItem("Hello world!");

    fw::Terminal::display(&defaultTitleItem);
    fw::Terminal::display(&titleItem);
    fw::Terminal::display(&textItem);

    return 0;
}
