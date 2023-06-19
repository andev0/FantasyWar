#include "MainMenu.h"

namespace fw
{
const MainMenu& MainMenu::getInstance()
{
    static MainMenu m_instance;

    return m_instance;
}

MainMenu::MainMenu()
{
    addMenuItem(std::make_unique<TitleMenuItem>("Main menu"));
    addMenuItem(std::make_unique<TextMenuItem>("Welcome to Fantasy War!"));

    addMenuOption("Exit game", [] {
        fw::Terminal::printLine("Quiting...");
        std::exit(0);
    });
    addMenuOption("Say hello", [] {
        fw::Terminal::printLine("Hello!");
    });

    addCommand("exit", [] {
        fw::Terminal::printLine("Quiting...");
        std::exit(0);
    });
}
} // namespace fw
