#include "Player.h"

namespace fw
{
Player& Player::getInstance()
{
    static Player player;

    return player;
}

Player::Player(const std::string& nickname)
    : Mob(10, 10)
    , m_nickname(nickname)
{ }

const std::string& Player::getNickname() const
{
    return m_nickname;
}

size_t Player::getLevel() const
{
    return m_level;
}

size_t Player::getGoldAmount() const
{
    return m_goldAmount;
}

size_t Player::getSkillPointsAmount() const
{
    return m_skillPointsAmount;
}

void Player::incrementLevel()
{
    ++m_level;
}

void Player::gainGold(size_t amount)
{
    m_goldAmount = amount;
}

void Player::gainSkillPoints(size_t amount)
{
    m_skillPointsAmount = amount;
}

void Player::spendGold(size_t amount)
{
    if (m_goldAmount > amount)
    {
        m_goldAmount -= amount;
    }
    else
    {
        m_goldAmount = 0;
    }
}

void Player::spendSkillPoints(size_t amount)
{
    if (m_skillPointsAmount > amount)
    {
        m_skillPointsAmount -= amount;
    }
    else
    {
        m_skillPointsAmount = 0;
    }
}

void Player::setNickname(const std::string& nickname)
{
    m_nickname = nickname;
}

void Player::setLevel(size_t level)
{
    m_level = level;
}

} // namespace fw
