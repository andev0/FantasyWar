#ifndef FW_TEXTFORMATTER_H
#define FW_TEXTFORMATTER_H

#include <string>
#include <regex>

namespace fw
{
    class TextFormatter
    {
    public:
        TextFormatter();
        virtual ~TextFormatter();

        std::string format(std::string text);

    protected:
        std::regex _formattingTagRegex;

        virtual std::string applyTag(const std::string& tagName, std::string text) = 0;

    };
}

#endif //FW_TEXTFORMATTER_H
