#include "InputMenuItem.h"

namespace fw
{
InputMenuItem::InputMenuItem(std::function<void(const std::string&)> processInput)
    : m_processInput(processInput)
{ }

void InputMenuItem::processInput(const std::string& input) const
{
    m_processInput(input);
}
} // namespace fw
