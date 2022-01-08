#ifndef FW_TELEGRAMTEXTFORMATTER_H
#define FW_TELEGRAMTEXTFORMATTER_H

#include "UserInterface/TextFormatting/TextFormatter.h"

#include "UserInterface/TextFormatting/Tags/ClosableFormattingTag.h"

namespace fw
{
    class TelegramTextFormatter : public TextFormatter
    {
    protected:
        virtual std::string applyTag(const std::string& tagName, std::string text) override;

        static std::vector<ClosableFormattingTag> _formattingTags;

    };
}

#endif //FW_TELEGRAMTEXTFORMATTER_H
