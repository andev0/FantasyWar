#include "Entity.h"

using namespace fw;

Entity::Entity (std::string name, unsigned int level, unsigned int attack, 
                unsigned int maxHealth) 
{
    _name = name;
    _level = level;
    _attack = attack;
    _health = _maxHealth = maxHealth;
}

void Entity::increaseLevel() 
{
    _level++;
}

void Entity::attack(Entity* target) 
{
    target->recieveDamage(_attack);
}
void Entity::recieveDamage(unsigned int damage) 
{
    if (_health >= damage)
    {
        _health -= damage;
    }
    else
    {
        _health = 0;
    }
}

std::string Entity::getName() 
{
    return _name;
}

unsigned int Entity::getLevel() 
{
    return _level;
}

unsigned int Entity::getAttack() 
{
    return _attack;
}

unsigned int Entity::getHealth() 
{
    return _health;
}
