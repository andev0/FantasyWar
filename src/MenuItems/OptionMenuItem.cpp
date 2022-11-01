#include "OptionMenuItem.h"

namespace fw
{
OptionMenuItem::OptionMenuItem(const std::string& text, std::function<void()> action)
    : TextMenuItem(text)
    , m_action(action)
{ }

void OptionMenuItem::invokeAction() const
{
    m_action();
}
} // namespace fw
