#ifndef FW_TEXTFORMATTER_H
#define FW_TEXTFORMATTER_H

#include <string>
#include <vector>
#include <regex>

#include "UserInterface/TextFormatting/Tags/FormattingTag.h"
#include "UserInterface/TextFormatting/Tags/ClosableFormattingTag.h"

namespace fw
{
    class TextFormatter
    {
    public:
        /**
         * Replaces a string with formatting tags to a formatted string.
         * @param text text to be formatted.
         * @param formattingTags vector with definition of how tags should be replaced.
         * @param previousFormatting sequence that will be placed before text outside the tags.
         */
        static std::string formatText(
            std::string text, 
            const std::vector<FormattingTag>& formattingTags,
            std::string previousFormatting = "\e[0m");

        /**
         * Replaces a string with formatting tags to a formatted string.
         * @param text text to be formatted.
         * @param formattingTags vector with definition of how tags should be replaced.
         */
        static std::string formatText(
            std::string text, 
            const std::vector<ClosableFormattingTag>& formattingTags);

    private:
        static std::regex formattingTagRegex;
    };
}

#endif //FW_TEXTFORMATTER_H