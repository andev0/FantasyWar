#ifndef FW_ENTITY_H
#define FW_ENTITY_H

#include <string>

#include "Console.h"

namespace fw
{
    class Entity
    {
    public:
        Entity (std::string name, unsigned int level, unsigned int attack, 
                unsigned int maxHealth);

        void increaseLevel();

        void attack(Entity* target);
        void recieveDamage(unsigned int damage);

        std::string getName();
        unsigned int getLevel();
        unsigned int getAttack();
        unsigned int getHealth();

        void printStats();

    protected:
        std::string _name;

        unsigned int _level;

        unsigned int _attack;
        unsigned int _health;
        unsigned int _maxHealth;
    };
}

#endif //FW_ENTITY_H
