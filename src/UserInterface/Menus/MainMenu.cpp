#include "MainMenu.h"

#include "YesNoPrompt.h"

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
        YesNoPrompt exitPrompt(
            "Are you sure you want to exit?", std::bind(std::exit, 0),
            std::bind(fw::Terminal::printLine, std::string("Not quiting...")));

        fw::Terminal::display(&exitPrompt);
    });
    addMenuOption("Say hello", [] {
        fw::Terminal::notify("Hello!");
    });

    addCommand("exit", [] {
        YesNoPrompt exitPrompt(
            "Are you sure you want to exit?", std::bind(std::exit, 0),
            std::bind(fw::Terminal::printLine, std::string("Not quiting...")));

        fw::Terminal::display(&exitPrompt);
    });
}
} // namespace fw
