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
        TextMenuItem modalQuestion("Are you sure you want to exit?");

        OptionsListMenuItem modalOptions;
        modalOptions.addOption(OptionMenuItem("Yes", []() {
            g_ui->popMenu();
        }));
        modalOptions.addOption(OptionMenuItem("No", []() {}));

        InputMenuOptionItem modalInput(modalOptions);

        g_ui->display(&modalQuestion);
        g_ui->display(&modalOptions);
        g_ui->display(&modalInput);
    }));
    options.addOption(OptionMenuItem("Display as modal", []() {
        g_ui->display(&g_mainMenu);
    }));
    options.addOption(OptionMenuItem("Push menu", []() {
        g_ui->pushMenu(&g_mainMenu);
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
