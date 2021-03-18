#include "Player.h"

using namespace fw;

Player::Player (std::string name, unsigned int attack, unsigned int maxHealth) 
    : fw::Entity::Entity(name, 1, attack, maxHealth)
{
    
}
