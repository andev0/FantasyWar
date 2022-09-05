#include "MainMenu.h"

namespace fw
{
MainMenu::MainMenu()
{
    m_menuItems.push_back(std::make_shared<TextMenuItem>("Some text"));
}
} // namespace fw
