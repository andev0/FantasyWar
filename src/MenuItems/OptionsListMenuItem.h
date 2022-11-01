#ifndef FW_OPTIONSLISTMENUITEM_H
#define FW_OPTIONSLISTMENUITEM_H

#include "Common/Includes.h"

#include "OptionMenuItem.h"

namespace fw
{

class OptionsListMenuItem : public MenuItem
{
public:
    OptionsListMenuItem() { }
    virtual ~OptionsListMenuItem() { }

    virtual const std::vector<std::unique_ptr<OptionMenuItem>>& getOptions() const
    {
        return m_options;
    }

    virtual void addOption(const OptionMenuItem& optionItem);

    virtual void popOption();

protected:
    std::vector<std::unique_ptr<OptionMenuItem>> m_options;
};

} // namespace fw

#endif // FW_OPTIONSLISTMENUITEM_H