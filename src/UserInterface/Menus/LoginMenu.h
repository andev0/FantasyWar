#ifndef FW_LOGINMENU_H
#define FW_LOGINMENU_H

#include "Menu.h"
#include "UserInterface/Terminal.h"

namespace fw
{

class LoginMenu : public Menu
{
public:
    static const LoginMenu& getInstance();

private:
    LoginMenu();
};

} // namespace fw

#endif // FW_LOGINMENU_H
