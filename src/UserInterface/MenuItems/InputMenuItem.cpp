#include "InputMenuItem.h"

namespace fw
{
InputMenuItem::InputMenuItem(const std::string& inputPrefix)
    : m_inputPrefix(inputPrefix)
{ }

const std::string& InputMenuItem::getText() const
{
    return m_inputPrefix;
}

void InputMenuItem::setResult(const std::string& result)
{
    m_result = result;
    m_onResultSet(result);
}

const std::string& InputMenuItem::getResult() const
{
    return m_result;
}

void InputMenuItem::invokeOnResultSet(
    const std::function<void(const std::string&)>& action)
{
    m_onResultSet = action;
}

} // namespace fw
