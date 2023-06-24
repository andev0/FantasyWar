#include <vector>

#include "UserInterface/Terminal.h"
#include "UserInterface/Menus/LoginMenu.h"

#include "Game/Player.h"

int main()
{
    fw::Player player("andev0");

    fw::Terminal::printLine(player.getNickname());
    fw::Terminal::printLine(std::to_string(player.getDamage()));
    fw::Terminal::printLine(std::to_string(player.getLevel()) + " ("
                            + std::to_string(player.getExperience()) + ")");
    player.recieveExperience(500);
    fw::Terminal::printLine(std::to_string(player.getLevel()) + " ("
                            + std::to_string(player.getExperience()) + ")");
    fw::Terminal::printLine(std::to_string(player.getHealth()) + "/"
                            + std::to_string(player.getMaxHealth()));
    player.recieveDamage(5);
    fw::Terminal::printLine(std::to_string(player.getHealth()) + "/"
                            + std::to_string(player.getMaxHealth()));

    fw::Terminal::readLine();

    fw::Terminal::display(&fw::LoginMenu::getInstance());

    return 0;
}
