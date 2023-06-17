#include "TitleMenuItem.h"

namespace fw
{

TitleMenuItem::TitleMenuItem(const std::string& title)
    : TextMenuItem(std::string("[ ") + title + " ]")
{ }

} // namespace fw
