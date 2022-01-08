#include "precompiled.h"

#include "CliTextFormatter.h"

namespace fw
{
    std::vector<FormattingTag> CliTextFormatter::m_formattingTags({
        {"red", "\e[31m"},
        {"green", "\e[32m"},
        {"yellow", "\e[33m"}
    });

    CliTextFormatter::CliTextFormatter()
        : m_previousFormattingSequences({"\e[0m"})
    {
        
    }

    std::string CliTextFormatter::applyTag(const std::string& tagName, std::string text) 
    {
        std::string formattingSequence = "";

        for (const FormattingTag& formattingTag : m_formattingTags)
        {
            if (tagName == formattingTag.getName())
            {
                formattingSequence = formattingTag.getStartingSequence();
                break;
            }
        }

        std::string previousFormatting;

        for (const std::string& previousFormattingSequence : m_previousFormattingSequences)
        {
            previousFormatting += previousFormattingSequence;
        }

        m_previousFormattingSequences.push_back(formattingSequence);

        std::string formattedText = formattingSequence + format(text) + previousFormatting;

        m_previousFormattingSequences.pop_back();

        return formattedText;
    }
}
