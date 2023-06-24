#include "Player.h"

namespace fw
{

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

size_t Player::getExperience() const
{
    return m_experience;
}

void Player::recieveExperience(size_t experience)
{
    m_experience += experience;
}

void Player::setNickname(const std::string& nickname)
{
    m_nickname = nickname;
}

void Player::setLevel(size_t level)
{
    m_level = level;
}

void Player::setExperience(size_t experience)
{
    m_experience = experience;
}

} // namespace fw
