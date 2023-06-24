#include "Mob.h"

namespace fw
{

Mob::Mob()
{
    assert(!isDead());
}

Mob::Mob(size_t maxHealth, size_t damage)
    : m_health(maxHealth)
    , m_maxHealth(maxHealth)
    , m_damage(damage)
{
    assert(!isDead());
}

size_t Mob::getDamage() const
{
    return m_damage;
}

size_t Mob::getHealth() const
{
    return m_health;
}

size_t Mob::getMaxHealth() const
{
    return m_maxHealth;
}

bool Mob::isDead() const
{
    return m_health == 0;
}

void Mob::recieveDamage(size_t damage)
{
    if (damage > m_health)
    {
        m_health = 0;
    }
    else
    {
        m_health -= damage;
    }
}

void Mob::setDamage(size_t damage)
{
    m_damage = damage;
}

void Mob::setHealth(size_t health)
{
    if (health > m_maxHealth)
    {
        m_health = m_maxHealth;
    }
    else
    {
        m_health = health;
    }
}

void Mob::setMaxHealth(size_t maxHealth)
{
    m_maxHealth = maxHealth;

    if (m_health > maxHealth)
    {
        m_health = maxHealth;
    }
}

} // namespace fw
