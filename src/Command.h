#ifndef FW_COMMAND_H
#define FW_COMMAND_H

#include <regex>

namespace fw
{

class Command
{
public:
    explicit Command(const std::string& pattern, const std::function<void()>& action);

    bool match(const std::string& text) const;

    void execute() const;

    bool executeOnMatch(const std::string& text) const;

private:
    std::regex m_pattern;
    std::function<void()> m_action;
};

} // namespace fw

#endif // FW_COMMAND_H
