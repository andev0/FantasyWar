#include "MainMenu.h"
#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/TextMenuItem.h"

namespace fw
{
MainMenu::MainMenu()
{
    m_menuItems.push_back(std::make_unique<TitleMenuItem>("Main menu"));
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Some text"));
}
} // namespace fw
