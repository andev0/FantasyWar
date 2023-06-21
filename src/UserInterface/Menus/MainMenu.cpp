#include "MainMenu.h"

#include "YesNoPrompt.h"

#include "UserInterface/MenuItems/DynamicTextMenuItem.h"
#include "LoginMenu.h"

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
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Welcome to Fantasy War, ") + fw::LoginMenu::nickname + "!";
    }));

    auto exitGame = [] {
        YesNoPrompt exitPrompt("Are you sure you want to exit?", std::bind(std::exit, 0),
                               [] {});

        fw::Terminal::display(&exitPrompt);
    };

    addMenuOption("Exit the game", exitGame);
    addMenuOption("Say hello", [] {
        fw::Terminal::notify("Hello!");
    });

    addCommand("exit", exitGame);
}
} // namespace fw
