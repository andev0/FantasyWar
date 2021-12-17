#include "TelegramTextFormatter.h"

namespace fw
{
    std::vector<ClosableFormattingTag> TelegramTextFormatter::_formattingTags({
        {"bold", "**", "**"},
        {"italic", "__", "__"},
    });

    std::string TelegramTextFormatter::applyTag(const std::string& tagName, std::string text) 
    {
        std::string prefix = "";
        std::string postfix = "";

        for (const ClosableFormattingTag& formattingTag : _formattingTags)
            {
                if (tagName == formattingTag.getName())
                {
                    prefix = formattingTag.getStartingSequence();
                    postfix = formattingTag.getEndingSequence();
                    break;
                }
            }

        return (prefix + text + postfix);
    }
}