#ifndef FW_DYNAMICTEXTMENUITEM_H
#define FW_DYNAMICTEXTMENUITEM_H

#include "TextMenuItem.h"

#include <functional>

namespace fw
{

class DynamicTextMenuItem : public TextMenuItem
{
public:
    explicit DynamicTextMenuItem(const std::function<std::string()>& textGenerator);

    const std::string& getText() const override;

private:
    std::function<std::string()> m_textGenerator;
};

} // namespace fw

#endif // FW_DYNAMICTEXTMENUITEM_H
