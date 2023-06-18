#ifndef FW_MAINMENU_H
#define FW_MAINMENU_H

#include "Menu.h"
#include "UserInterface/Terminal.h"

namespace fw
{

class MainMenu : public Menu
{
public:
    static const MainMenu& getInstance();

private:
    MainMenu();
};

} // namespace fw

#endif // FW_MAINMENU_H
