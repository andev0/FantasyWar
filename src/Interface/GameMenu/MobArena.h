#ifndef FW_MOBARENA_H
#define FW_MOBARENA_H

#include <string>

#include <fmt/format.h>

#include "Extensions/StringExtensions.h"

#include "Interface/MenuAction.h"
#include "Interface/GameMenu.h"
#include "Interface/Dialog.h"

#include "Console.h"

namespace fw
{
    class MobArena : public GameMenu
    {
    public:
        MobArena(std::string key, std::string name);

        void show(Player& player) override;

    protected:
        void fight(Player& player, Entity& enemy);

        void printStats(Entity& target);

    };
}

#endif //FW_MOBARENA_H