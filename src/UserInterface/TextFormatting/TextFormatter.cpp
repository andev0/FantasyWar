#include "TextFormatter.h"

namespace fw
{
    std::regex TextFormatter::formattingTagRegex("<([a-zA-Z]*?)>((?:.|\n)*?)<\\/\\1>");

    std::string TextFormatter::formatText(std::string text, 
                                          const std::vector<FormattingTag>& formattingTags,
                                          std::string previousFormatting) 
    {
        while (std::regex_search(text, formattingTagRegex))
        {
            auto tokenMatch = 
                std::sregex_iterator(text.begin(), text.end(), formattingTagRegex);

            std::string tag = (*tokenMatch)[1];
            std::string content = (*tokenMatch)[2];

            std::string prefix = "";
            std::string postfix = "";

            text.erase(tokenMatch->position(), (*tokenMatch).str().size());

            for (const FormattingTag& formattingTag : formattingTags)
            {
                if (tag == formattingTag.getName())
                {
                    prefix = formattingTag.getStartingSequence();
                    postfix = formattingTag.getEndingSequence();
                }
            }

            if (postfix == "")
            {
                text.insert(tokenMatch->position(), 
                    prefix
                    + formatText(content, formattingTags, previousFormatting + prefix)
                    + previousFormatting);
            }
            else
            {
                text.insert(tokenMatch->position(), 
                    prefix + formatText(content, formattingTags) + postfix);
            }
        }

        return text;
    }
}