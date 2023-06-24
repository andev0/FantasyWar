#ifndef FW_MOB_H
#define FW_MOB_H

#include <cstddef>
#include <assert.h>

namespace fw
{

class Mob
{
public:
    Mob();
    Mob(size_t maxHealth, size_t damage);

    size_t getDamage() const;
    size_t getHealth() const;
    size_t getMaxHealth() const;

    bool isDead() const;

    void recieveDamage(size_t damage);

protected:
    void setDamage(size_t damage);
    void setHealth(size_t health);
    void setMaxHealth(size_t maxHealth);

private:
    size_t m_health {10};
    size_t m_maxHealth {10};

    size_t m_damage {0};
};

} // namespace fw

#endif // FW_MOB_H
