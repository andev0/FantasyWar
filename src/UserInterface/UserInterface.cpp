#include "UserInterface.h"

namespace fw
{
void UserInterface::display(const Menu* menu) const
{
    for (const auto& menuItem : menu->getMenuItems())
    {
        display(menuItem.get());
    }
}

UserInterface::~UserInterface() { }
} // namespace fw
