#ifndef FW_TEXTFORMATTER_H
#define FW_TEXTFORMATTER_H

#include <string>
#include <vector>
#include <regex>

#include "UserInterface/TextFormatting/FormattingTag.h"

namespace fw
{
    class TextFormatter
    {
    public:
        /// Method for replacing a string with formatting tags to a formatted string.
        /// Arguments:
        /// @ text - text to be formatted
        /// @ formattingTags - vector with definition of how tags should be replaced
        /// @ previousFormatting - Sequence that will be placed before text outside the tags    
        static std::string formatText(std::string text, 
                                      const std::vector<FormattingTag>& formattingTags,
                                      std::string previousFormatting = "\e[0m");

    private:
        static std::regex formattingTagRegex;
    };
}

#endif //FW_TEXTFORMATTER_H