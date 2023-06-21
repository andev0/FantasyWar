#include "LoginMenu.h"

#include "MainMenu.h"
#include "YesNoPrompt.h"

namespace fw
{
const LoginMenu& LoginMenu::getInstance()
{
    static LoginMenu m_instance;

    return m_instance;
}

LoginMenu::LoginMenu()
{
    InputMenuItem* loginInput = new InputMenuItem();

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
            YesNoPrompt ensurance(
                "Did you type the nickname correctly?",
                [&input] {
                    nickname = input;
                    while (true)
                    {
                        system("clear");
                        fw::Terminal::display(&MainMenu::getInstance());
                    }
                },
                [] {
                    fw::Terminal::display(&LoginMenu::getInstance());
                });

            fw::Terminal::display(&ensurance);
        }
    });
}
} // namespace fw
