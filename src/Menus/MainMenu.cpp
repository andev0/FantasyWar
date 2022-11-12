#include "Common/Globals.h"

#include "MainMenu.h"

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/OptionsListMenuItem.h"
#include "MenuItems/InputMenuItem.h"

namespace fw
{
MainMenu::MainMenu()
{
    OptionsListMenuItem options(0);

    options.addOption(OptionMenuItem("Exit", []() {
        g_ui->display("Goodbye!");
        std::exit(0);
    }));
    options.addOption(OptionMenuItem("Sword", []() {
        g_ui->display("The sword is chosen!");
    }));
    options.addOption(OptionMenuItem("Shield", []() {
        g_ui->display("The shield is chosen!");
    }));
    options.addOption(OptionMenuItem("Spear", []() {
        g_ui->display("The spear is chosen!");
    }));
    std::unique_ptr<InputMenuItem> input(
        new InputMenuItem([options](const std::string& input) {
            size_t optionIndex = stringTo<size_t>(input);

            for (size_t i = 0; i < options.getOptions().size(); ++i)
            {
                if (optionIndex == i)
                {
                    options.getOptions()[i]->invokeAction();
                    return;
                }
            }

            g_ui->display("Please enter the option index from the menu above.");
        }));

    m_menuItems.push_back(std::make_unique<TitleMenuItem>("Main menu"));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Choose your weapon:"));
    m_menuItems.push_back(std::make_unique<OptionsListMenuItem>(options));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Please, select an option."));
    m_menuItems.push_back(std::move(input));
}
} // namespace fw
