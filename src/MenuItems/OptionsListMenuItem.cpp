#include "OptionsListMenuItem.h"

namespace fw
{

OptionsListMenuItem::OptionsListMenuItem(const OptionsListMenuItem& other)
{
    m_options.reserve(other.getOptions().size());

    for (const auto& optionMenuItem : other.getOptions())
    {
        m_options.push_back(std::make_unique<OptionMenuItem>(*optionMenuItem.get()));
    }
}

void OptionsListMenuItem::addOption(const OptionMenuItem& optionItem)
{
    m_options.push_back(std::make_unique<OptionMenuItem>(optionItem));
}

void OptionsListMenuItem::popOption()
{
    m_options.pop_back();
}

} // namespace fw