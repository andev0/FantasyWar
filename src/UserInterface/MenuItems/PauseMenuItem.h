#ifndef FW_PAUSEMENUITEM_H
#define FW_PAUSEMENUITEM_H

#include "TextMenuItem.h"

namespace fw
{

class PauseMenuItem : public TextMenuItem
{
public:
    explicit PauseMenuItem(const std::string& text = "\nPress Enter to continue.");
};

} // namespace fw

#endif // FW_PAUSEMENUITEM_H
