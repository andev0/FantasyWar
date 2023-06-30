#include "LoginMenu.h"

#include "MainMenu.h"
#include "YesNoPrompt.h"

#include "Game/Player.h"

namespace fw
{

const LoginMenu& LoginMenu::getInstance()
{
    static LoginMenu m_instance;

    return m_instance;
}

LoginMenu::LoginMenu()
{
    auto* loginInput = new InputMenuItem();

    addMenuItem(std::make_unique<TitleMenuItem>("Login"));
    addMenuItem(std::make_unique<TextMenuItem>("Please, enter your nickname."));
    addMenuItem(std::make_unique<TextMenuItem>("Enter \"0\" to exit the game."));

    addMenuItem(std::unique_ptr<InputMenuItem>(loginInput));

    loginInput->invokeOnResultSet([](const std::string& input) {
        Terminal::popMenuStack(); // Removing login menu itself.

        if (input != "0")
        {
            Player::getInstance().setNickname(input);

            Terminal::pushMenuStack(&MainMenu::getInstance());
        }
    });
}

} // namespace fw
