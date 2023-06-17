#ifndef FW_MENUITEM_H
#define FW_MENUITEM_H

#include <string>

namespace fw
{

class MenuItem
{
public:
    virtual ~MenuItem() = 0;

    virtual const std::string& getText() const = 0;
};

} // namespace fw

#endif // FW_MENUITEM_H
