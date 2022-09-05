#ifndef FW_MAINMENU_H
#define FW_MAINMENU_H

#include "Menu.h"
#include "MenuItems/TextMenuItem.h"

namespace fw
{
class MainMenu : public Menu
{
public:
    MainMenu();
    virtual ~MainMenu() override { }
};
} // namespace fw

#endif // FW_MAINMENU_H
