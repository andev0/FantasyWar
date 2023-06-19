#include "Command.h"

namespace fw
{

Command::Command(const std::string& pattern, const std::function<void()>& action)
    : m_pattern(pattern)
    , m_action(action)
{ }

bool Command::match(const std::string& text) const
{
    std::smatch match;

    return std::regex_match(text, match, m_pattern);
}

void Command::execute() const
{
    m_action();
}

bool Command::executeOnMatch(const std::string& text) const
{
    bool isMatched = match(text);

    if (isMatched)
        execute();

    return isMatched;
}

} // namespace fw
