#include "Action.h"

namespace fw
{
Action::Action(const std::string& name, const std::function<void()>& action)
    : m_name(name)
    , m_action(action)
{ }

const std::string& Action::getName() const
{
    return m_name;
}

void Action::execute() const
{
    m_action();
}
} // namespace fw
