#ifndef FW_PLAYER_H
#define FW_PLAYER_H

#include "Entity.h"

namespace fw
{
    class Player : public Entity
    {
    public:
        Player (std::string name, unsigned int attack, unsigned int maxHealth);

        void increaseExperience(unsigned int expirience);
        unsigned int getExperience();

    protected:
        unsigned int _expirience;
    };
}

#endif //FW_PLAYER_H
