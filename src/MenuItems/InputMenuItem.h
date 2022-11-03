#ifndef FW_INPUTMENUITEM_H
#define FW_INPUTMENUITEM_H

#include "Common/Includes.h"

#include "MenuItem.h"

namespace fw
{
class InputMenuItem : public MenuItem
{
public:
    explicit InputMenuItem(std::function<void(const std::string&)> processInput);
    virtual ~InputMenuItem() { }

    virtual void processInput(const std::string& input) const;

protected:
    std::function<void(const std::string&)> m_processInput;
};
} // namespace fw

#endif // FW_INPUTMENUITEM_H
