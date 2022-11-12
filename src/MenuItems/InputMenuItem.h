#ifndef FW_INPUTMENUITEM_H
#define FW_INPUTMENUITEM_H

#include "Common/Includes.h"

#include "MenuItem.h"

namespace fw
{
class InputMenuItem : public MenuItem
{
public:
    explicit InputMenuItem(std::function<void(const std::string&)> processInput,
                           const std::string& inputPrefix = "> ");
    virtual ~InputMenuItem() { }

    virtual void processInput(const std::string& input) const;

    virtual const std::string& getInputPrefix() const { return m_inputPrefix; }

protected:
    std::function<void(const std::string&)> m_processInput;

    std::string m_inputPrefix;
};
} // namespace fw

#endif // FW_INPUTMENUITEM_H
