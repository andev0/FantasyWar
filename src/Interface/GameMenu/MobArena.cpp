#include "MobArena.h"

using namespace fw;

MobArena::MobArena(std::string key, std::string name)
    : GameMenu(key, name)
{
    
}

void MobArena::Show(Player& player) 
{
    while(true)
    {
        Console::clear();
        std::string action = Console::dialog("> " + Translations::translate("Mob arena") + " <", 
                                             {"Back", "Find mob"});

        if (action == "0")
        {
            break;
        }
        else if (action == "1")
        {
            Entity mob("Your enemy", 1, 5, 10);

            while(true)
            {
                Console::clear();
                player.printStats();
                mob.printStats();
                std::string action = Console::dialog("\n> " + Translations::translate("Fighting") + " <", 
                                                     {"Attack"});
                if (action == "0")
                {
                    Console::print(player.getName() + " " + Translations::translate("attacks") + 
                    " " + mob.getName() + " " + Translations::translate("by") + " " + 
                    std::to_string(player.getAttack()) + " " + 
                    Translations::translate("damage") + ".");
                    player.attack(&mob);

                    Console::print(mob.getName() + " " + Translations::translate("attacks") + 
                    " " + player.getName() + " " + Translations::translate("by") + " " + 
                    std::to_string(mob.getAttack()) + " " + 
                    Translations::translate("damage") + ".");
                    mob.attack(&player);
                }

                if (mob.getHealth() <= 0)
                {
                    Console::pause("\n" + Translations::translate("You killed") + " " + mob.getName());
                    break;
                }
            }
        }
    }
}
