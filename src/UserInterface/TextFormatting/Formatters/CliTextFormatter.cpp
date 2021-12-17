#include "CliTextFormatter.h"

namespace fw
{
    std::vector<FormattingTag> CliTextFormatter::_formattingTags({
        {"red", "\e[31m"},
        {"green", "\e[32m"},
        {"yellow", "\e[33m"}
    });

    CliTextFormatter::CliTextFormatter()
        : _previousFormattingSequences({"\e[0m"})
    {
        
    }

    std::string CliTextFormatter::applyTag(const std::string& tagName, std::string text) 
    {
        std::string prefix = "";
        
        for (const FormattingTag& formattingTag : _formattingTags)
        {
            if (tagName == formattingTag.getName())
            {
                prefix = formattingTag.getStartingSequence();
                break;
            }
        }

        std::string previousFormatting;

        for (const std::string& formattingSequence : _previousFormattingSequences)
        {
            previousFormatting += formattingSequence;
        }

        return (prefix + format(text) + previousFormatting);
    }
}