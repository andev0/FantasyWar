#ifndef FW_TITLEMENUITEM_H
#define FW_TITLEMENUITEM_H

#include "TextMenuItem.h"

namespace fw
{

class TitleMenuItem : public TextMenuItem
{
public:
    explicit TitleMenuItem(const std::string& title = "Your title could be here");
};

} // namespace fw

#endif // FW_TITLEMENUITEM_H
