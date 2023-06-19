#include "YesNoPrompt.h"

namespace fw
{

YesNoPrompt::YesNoPrompt(const std::string& question,
                         const std::function<void()>& onYesChoosed,
                         const std::function<void()>& onNoChoosed)
{
    addMenuItem(std::make_unique<TextMenuItem>(question));

    addMenuOption("No", onNoChoosed);
    addMenuOption("Yes", onYesChoosed);
}

} // namespace fw
