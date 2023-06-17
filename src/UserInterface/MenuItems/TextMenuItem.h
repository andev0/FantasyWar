#ifndef FW_TEXTMENUITEM_H
#define FW_TEXTMENUITEM_H

#include "MenuItem.h"

namespace fw
{
class TextMenuItem : public MenuItem
{
public:
    explicit TextMenuItem(const std::string& text = "");

    const std::string& getText() const override;

private:
    std::string m_text;
};
} // namespace fw

#endif // FW_TEXTMENUITEM_H
