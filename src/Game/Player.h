#ifndef FW_PLAYER_H
#define FW_PLAYER_H

#include "Mob.h"

#include <string>

#include "UserInterface/Menus/LoginMenu.h"

namespace fw
{

class Player : public Mob
{
public:
    static Player& getInstance();

    const std::string& getNickname() const;
    size_t getLevel() const;

    void incrementLevel();

protected:
    explicit Player(const std::string& nickname = "");
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;

    void setNickname(const std::string& nickname);
    void setLevel(size_t level);

    friend class LoginMenu;

private:
    std::string m_nickname;

    size_t m_level {0};
};

} // namespace fw

#endif // FW_PLAYER_H
