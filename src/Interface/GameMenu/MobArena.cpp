#include "MobArena.h"

#include "Extensions/Aliases.h"

using namespace fw;

MobArena::MobArena(std::string key, std::string name)
    : GameMenu(key, name)
{
    
}

void MobArena::show(Player& player) 
{
    bool isExiting = false;

    static Dialog menuDialog(makeTitle("Mob arena"), {
        MenuAction("Back", "0", [&isExiting]() { 
            isExiting = true;
        }),

        MenuAction("Find mob", "1", [&player, this]() { 
            Entity mob("Your enemy", 1, 5, 10);

            this->fight(player, mob);
        })
    });

    while(!isExiting)
    {
        Console::clear();
        
        menuDialog.show();
    }
}

void MobArena::fight(Player& player, Entity& enemy) 
{
    static Dialog menuDialog(makeTitle("Fight"), {
        MenuAction("Attack", "0", [&player, &enemy]() { 
            // Player attacks enemy.

            Console::printLine( fmt::format(translate("{0} attacks {1} by {2} damage."), 
                                player.getName(), enemy.getName(), 
                                player.getAttack()) );

            player.attack(&enemy);

            // Enemy attacks player.

            Console::printLine( fmt::format(translate("{0} attacks {1} by {2} damage."), 
                                enemy.getName(), player.getName(), 
                                player.getAttack()) );
            
            enemy.attack(&player);
        })
    });

    while(true)
    {
        Console::clear();

        printStats(player);
        printStats(enemy);

        Console::printLine();

        menuDialog.show();

        if (player.getHealth() <= 0)
        {
            Console::printLine();
            Console::printLine( fmt::format(translate("You was killed by {0}."), 
                                enemy.getName()) );
            Console::printLine();

            Console::pause(translate("Press Enter to exit."));
            std::exit(0);

            break;
        }
        else if (enemy.getHealth() <= 0)
        {
            Console::printLine();
            Console::printLine( fmt::format(translate("You killed {0}."), 
                                enemy.getName()) );
            Console::printLine();

            Console::pause(translate("Press Enter to continue."));
            break;
        }
    }
}

void MobArena::printStats(Entity& target) 
{
    Console::printLine(fmt::format(translate("{0} ({1} level) [{2}/{3} health]"), 
                                   target.getName(), target.getLevel(), 
                                   target.getHealth(), target.getMaxHealth()));
}
