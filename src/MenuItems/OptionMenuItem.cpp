#include "OptionMenuItem.h"

namespace fw
{
void OptionMenuItem::invokeAction() const
{
    m_action();
}
} // namespace fw
