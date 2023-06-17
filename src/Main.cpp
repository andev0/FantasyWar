#include "UserInterface/Terminal.h"
#include "UserInterface/MenuItems/TextMenuItem.h"

int main()
{
    fw::TextMenuItem textItem("Hello world!");
    fw::Terminal::printLine(textItem.getText());

    return 0;
}
