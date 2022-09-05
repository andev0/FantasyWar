#ifndef FW_TEXTMENUITEM_H
#define FW_TEXTMENUITEM_H

#include "Common/Includes.h"

#include "MenuItem.h"

namespace fw
{
class TextMenuItem : public MenuItem
{
public:
    explicit TextMenuItem(const std::string& text);
    virtual ~TextMenuItem() { }

    const std::string& getText() const { return m_text; }

protected:
    std::string m_text;
};
} // namespace fw

#endif // FW_TEXTMENUITEM_H
