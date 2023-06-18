#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/MenuItems/TitleMenuItem.h"
#include "Action.h"

int main()
{
    fw::TitleMenuItem defaultTitleItem;
    fw::TitleMenuItem titleItem("Fantasy War");
    fw::TextMenuItem textItem("Hello world!");
    fw::InputMenuItem inputItem;

    std::vector<fw::Action> actions {
        fw::Action("Print hi",
                   [] {
                       fw::Terminal::printLine("Hi");
                   }),
        fw::Action("Print hello",
                   [] {
                       fw::Terminal::printLine("Hello");
                   }),
    };

    fw::Terminal::display(&defaultTitleItem);
    fw::Terminal::display(&titleItem);
    fw::Terminal::display(&textItem);

    for (const auto& action : actions)
    {
        fw::Terminal::printLine(action.getName() + ":");
        action.execute();
        fw::Terminal::printLine();
    }

    fw::Terminal::display(&inputItem);
    fw::Terminal::printLine(std::string("You wrote: \"") + inputItem.getResult() + "\"");

    return 0;
}
