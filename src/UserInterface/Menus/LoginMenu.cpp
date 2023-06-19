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
    addMenuItem(std::make_unique<TitleMenuItem>("Login"));
    addMenuItem(std::make_unique<TextMenuItem>("Please, enter your nickname."));
    addMenuItem(std::make_unique<TextMenuItem>(
        "Nickname can contain English letters and numbers."));

    addMenuOption("Exit game", [] {
        std::exit(0);
    });

    addCommand("[a-zA-Z0-9]+", [] {
        YesNoPrompt ensurance(
            "Did you typed nickname correctly?",
            [] {
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
    });
}
} // namespace fw
