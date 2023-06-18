#include "InputMenuItem.h"

namespace fw
{

const std::string& InputMenuItem::getText() const
{
    return s_inputPrefix;
}

void InputMenuItem::setResult(const std::string& result)
{
    m_result = result;
}

const std::string& InputMenuItem::getResult() const
{
    return m_result;
}

} // namespace fw
