#include "MainMenu.h"
#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/OptionsListMenuItem.h"

namespace fw
{
MainMenu::MainMenu()
{
    std::unique_ptr<OptionsListMenuItem> options(new OptionsListMenuItem);

    options->addOption(OptionMenuItem("Sword", []() {
        std::cout << "The sword is chosen!";
    }));
    options->addOption(OptionMenuItem("Shield", []() {
        std::cout << "The shield is chosen!";
    }));
    options->addOption(OptionMenuItem("Spear", []() {
        std::cout << "The spear is chosen!";
    }));

    m_menuItems.push_back(std::make_unique<TitleMenuItem>("Main menu"));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Choose your weapon:"));
    m_menuItems.push_back(std::move(options));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Everything is printed."));
}
} // namespace fw
