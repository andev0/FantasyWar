#include "Common/Globals.h"

#include "InputMenuOptionItem.h"

namespace fw
{
InputMenuOptionItem::InputMenuOptionItem(const OptionsListMenuItem& optionsList)
    : InputMenuItem([optionsList, this](const std::string& input) {
        try
        {
            // If input can't be parsed, an invalid_argument exception will be thrown.
            size_t optionIndex = stringTo<size_t>(input) - optionsList.getStartingIndex();

            for (size_t i = 0; i < optionsList.getOptions().size(); ++i)
            {
                if (optionIndex == i)
                {
                    optionsList.getOptions()[i]->invokeAction();
                    return;
                }
            }

            // Just to not duplicate code from catch block.
            throw std::invalid_argument("");
        }
        catch (const std::invalid_argument& ex)
        {
            this->m_inputPrefix = "Please enter the option index from the menu above.\n"
                                  "> ";
            g_ui->display(this);
            this->m_inputPrefix = "> ";
        }
    })
{ }
} // namespace fw