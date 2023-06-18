#ifndef FW_ACTION_H
#define FW_ACTION_H

#include <string>
#include <functional>

namespace fw
{

class Action
{
public:
    Action(
        const std::string& name = "", const std::function<void()>& action = [] {});

    const std::string& getName() const;

    void execute() const;

private:
    std::string m_name;
    std::function<void()> m_action;
};

} // namespace fw

#endif // FW_ACTION_H
