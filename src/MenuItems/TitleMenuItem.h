#ifndef FW_TITLEMENUITEM_H
#define FW_TITLEMENUITEM_H

#include "Common/Includes.h"

#include "MenuItem.h"

namespace fw
{
class TitleMenuItem : public MenuItem
{
public:
    explicit TitleMenuItem(const std::string& title);
    virtual ~TitleMenuItem() { }

    const std::string& getTitle() const { return m_title; }

protected:
    std::string m_title;
};
} // namespace fw

#endif // FW_TITLEMENUITEM_H
