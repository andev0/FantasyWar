#ifndef FW_PLAYERMENU_H
#define FW_PLAYERMENU_H

#include "Menu.h"
#include "UserInterface/Terminal.h"

namespace fw
{

class PlayerMenu : public Menu
{
public:
    static const PlayerMenu& getInstance();

private:
    PlayerMenu();
};

} // namespace fw

#endif // FW_PLAYERMENU_H
