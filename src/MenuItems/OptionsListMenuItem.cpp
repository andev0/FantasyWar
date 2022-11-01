#include "OptionsListMenuItem.h"

namespace fw
{

void OptionsListMenuItem::addOption(const OptionMenuItem& optionItem)
{
    m_options.push_back(std::make_unique<OptionMenuItem>(optionItem));
}

void OptionsListMenuItem::popOption()
{
    m_options.pop_back();
}

} // namespace fw