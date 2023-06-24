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
    InputMenuItem* loginInput = new InputMenuItem("\n> ");

    addMenuItem(std::make_unique<TitleMenuItem>("Login"));
    addMenuItem(std::make_unique<TextMenuItem>("Please, enter your nickname."));
    addMenuItem(std::make_unique<TextMenuItem>("Enter \"0\" to exit the game."));

    addMenuItem(std::unique_ptr<InputMenuItem>(loginInput));

    loginInput->invokeOnResultSet([](const std::string& input) {
        if (input == "0")
        {
            std::exit(0);
        }
        else
        {
            Player::getInstance().setNickname(input);

            while (true)
            {
                Terminal::clear();

                Terminal::display(&MainMenu::getInstance());
            }
        }
    });
}

} // namespace fw
