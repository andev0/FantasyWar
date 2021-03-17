#include "Player.h"

using namespace fw;

Player::Player (std::string name, unsigned int attack, unsigned int maxHealth) 
    : fw::Entity::Entity(name, 1, attack, maxHealth)
{
    _expirience = 0;
}

void Player::increaseExperience(unsigned int expirience) 
{
    // TODO: increasing level.

    _expirience = expirience;
}

unsigned int Player::getExperience() 
{
    return _expirience;
}
