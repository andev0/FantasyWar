#include "MainMenu.h"

namespace fw
{
MainMenu::MainMenu()
{
    m_menuItems.push_back(std::make_unique<TextMenuItem>("Some text"));
}
} // namespace fw
