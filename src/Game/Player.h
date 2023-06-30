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
    size_t getGoldAmount() const;
    size_t getSkillPointsAmount() const;

    void incrementLevel();

    void gainGold(size_t amount);
    void gainSkillPoints(size_t amount);

    void spendGold(size_t amount);
    void spendSkillPoints(size_t amount);

protected:
    explicit Player(const std::string& nickname = "");
    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;

    void setNickname(const std::string& nickname);
    void setLevel(size_t level);

    friend class LoginMenu;
    friend class PlayerMenu;

private:
    std::string m_nickname;

    size_t m_level {0};
    size_t m_goldAmount {10};
    size_t m_skillPointsAmount {10};
};

} // namespace fw

#endif // FW_PLAYER_H
