#ifndef FW_YESNOPROMPT_H
#define FW_YESNOPROMPT_H

#include "Menu.h"
#include "UserInterface/Terminal.h"

namespace fw
{

class YesNoPrompt : public Menu
{
public:
    YesNoPrompt() = default;

    explicit YesNoPrompt(const std::string& question,
                         const std::function<void()>& onYesChoosed,
                         const std::function<void()>& onNoChoosed);
};

} // namespace fw

#endif // FW_YESNOPROMPT_H
