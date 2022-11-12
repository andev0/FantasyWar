#include "InputMenuItem.h"

namespace fw
{
InputMenuItem::InputMenuItem(std::function<void(const std::string&)> processInput,
                             const std::string& inputPrefix)
    : m_processInput(processInput)
    , m_inputPrefix(inputPrefix)
{ }

void InputMenuItem::processInput(const std::string& input) const
{
    m_processInput(input);
}
} // namespace fw
