#ifndef FW_INPUTOPTIONSMENUITEM_H
#define FW_INPUTOPTIONSMENUITEM_H

#include "InputMenuItem.h"
#include "OptionsListMenuItem.h"

namespace fw
{
class InputMenuOptionItem : public InputMenuItem
{
public:
    explicit InputMenuOptionItem(const OptionsListMenuItem& optionsList);
    virtual ~InputMenuOptionItem() { }
};
} // namespace fw

#endif // FW_INPUTOPTIONSMENUITEM_H