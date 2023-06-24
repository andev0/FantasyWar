#ifndef FW_PLAYER_H
#define FW_PLAYER_H

#include "Mob.h"

#include <string>

namespace fw
{

class Player : public Mob
{
public:
    explicit Player(const std::string& nickname = "");

    const std::string& getNickname() const;
    size_t getLevel() const;
    size_t getExperience() const;

    void recieveExperience(size_t experience);

protected:
    void setNickname(const std::string& nickname);
    void setLevel(size_t level);
    void setExperience(size_t experience);

private:
    std::string m_nickname;

    size_t m_level {0};
    size_t m_experience {0};
};

} // namespace fw

#endif // FW_PLAYER_H
