#ifndef FW_OPTIONMENUITEM_H
#define FW_OPTIONMENUITEM_H

#include "Common/Includes.h"

#include "TextMenuItem.h"

namespace fw
{
class OptionMenuItem : public TextMenuItem
{
public:
    void invokeAction() const;

protected:
    std::function<void()> m_action;
};
} // namespace fw

#endif // FW_OPTIONMENUITEM_H
