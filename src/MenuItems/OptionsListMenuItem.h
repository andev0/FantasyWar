#ifndef FW_OPTIONSLISTMENUITEM_H
#define FW_OPTIONSLISTMENUITEM_H

#include "Common/Includes.h"

#include "OptionMenuItem.h"

namespace fw
{

class OptionsListMenuItem : public MenuItem
{
public:
    /// @param startingIndex doesn't change the order in which items are stored in options
    /// vector but just can be used to display the menu.
    explicit OptionsListMenuItem(size_t startingIndex = 1);
    OptionsListMenuItem(const OptionsListMenuItem& other);
    virtual ~OptionsListMenuItem() { }

    virtual const std::vector<std::unique_ptr<OptionMenuItem>>& getOptions() const
    {
        return m_options;
    }

    virtual void addOption(const OptionMenuItem& optionItem);

    virtual void popOption();

    virtual size_t getStartingIndex() const { return m_startingIndex; }

protected:
    std::vector<std::unique_ptr<OptionMenuItem>> m_options;

    size_t m_startingIndex;
};

} // namespace fw

#endif // FW_OPTIONSLISTMENUITEM_H