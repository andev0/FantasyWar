#include "Common/Globals.h"

#include "MainMenu.h"

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/InputMenuOptionItem.h"

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

    m_menuItems.push_back(std::make_unique<TitleMenuItem>("Main menu"));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Choose your weapon:"));
    m_menuItems.push_back(std::make_unique<OptionsListMenuItem>(options));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Please, select an option."));
    m_menuItems.push_back(std::make_unique<InputMenuOptionItem>(options));
}
} // namespace fw
