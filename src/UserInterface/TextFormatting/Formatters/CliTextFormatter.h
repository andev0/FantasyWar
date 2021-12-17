#ifndef FW_CLITEXTFORMATTER_H
#define FW_CLITEXTFORMATTER_H

#include "UserInterface/TextFormatting/TextFormatter.h"

#include <vector>

#include "UserInterface/TextFormatting/Tags/FormattingTag.h"

namespace fw
{
    class CliTextFormatter : public TextFormatter
    {
    public:
        CliTextFormatter();

    protected:
        virtual std::string applyTag(const std::string& tagName, std::string text) override;

        std::vector<std::string> _previousFormattingSequences;

        static std::vector<FormattingTag> _formattingTags;

    };
}

#endif //FW_CLITEXTFORMATTER_H