#ifndef FW_MOBARENA_H
#define FW_MOBARENA_H

#include <string>

#include "Interface/GameMenu.h"
#include "Console.h"

namespace fw
{
    class MobArena : public GameMenu
    {
    public:
        MobArena(std::string key, std::string name);

        void Show(Player& player) override;
    };
}

#endif //FW_MOBARENA_H