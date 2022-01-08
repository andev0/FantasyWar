#include "precompiled.h"

#include "TextFormatter.h"

namespace fw
{
    TextFormatter::TextFormatter() 
        : m_formattingTagRegex("<([a-zA-Z]*?)>((?:.|\n)*?)<\\/\\1>")
    {
        
    }

    TextFormatter::~TextFormatter()
    {
        
    }

    std::string TextFormatter::format(std::string text) 
    {
        while (std::regex_search(text, m_formattingTagRegex))
        {
            auto tokenMatch = 
                std::sregex_iterator(text.begin(), text.end(), m_formattingTagRegex);

            std::string tag = (*tokenMatch)[1];
            std::string content = (*tokenMatch)[2];

            text.erase(tokenMatch->position(), (*tokenMatch).str().size());

            text.insert(tokenMatch->position(), applyTag(tag, content));
        }

        return text;
    }
}
