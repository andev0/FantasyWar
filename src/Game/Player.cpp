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

void Player::incrementLevel()
{
    ++m_level;
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
