#include "PlayerMenu.h"

#include "UserInterface/MenuItems/DynamicTextMenuItem.h"
#include "Game/Player.h"

#include "UserInterface/MenuItems/PauseMenuItem.h"

namespace fw
{

const PlayerMenu& PlayerMenu::getInstance()
{
    static const PlayerMenu instance;

    return instance;
}

PlayerMenu::PlayerMenu()
{
    addMenuItem(std::make_unique<TitleMenuItem>("Statistics"));

    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return Player::getInstance().getNickname() + " ("
               + std::to_string(Player::getInstance().getLevel()) + ")";
    }));
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Damage: ")
               + std::to_string(Player::getInstance().getDamage());
    }));
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Health: ") + std::to_string(Player::getInstance().getHealth())
               + "/" + std::to_string(Player::getInstance().getMaxHealth());
    }));

    addMenuItem(std::make_unique<PauseMenuItem>());
}

} // namespace fw
