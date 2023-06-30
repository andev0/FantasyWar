#include "MainMenu.h"

#include "YesNoPrompt.h"
#include "PlayerMenu.h"

#include "UserInterface/MenuItems/DynamicTextMenuItem.h"

#include "Game/Player.h"

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
        return std::string("Welcome to Fantasy War, ")
               + Player::getInstance().getNickname() + "!";
    }));

    auto exitGame = [] {
        YesNoPrompt exitPrompt("Are you sure you want to exit?", Terminal::popMenuStack,
                               [] {});

        Terminal::display(&exitPrompt);
    };

    addMenuOption("Exit the game", exitGame);
    addMenuOption("Player", [] {
        Terminal::pushMenuStack(&PlayerMenu::getInstance());
    });

    addCommand("exit", exitGame);
}
} // namespace fw
