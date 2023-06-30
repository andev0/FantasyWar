#ifndef FW_FORMATTER_H
#define FW_FORMATTER_H

#include <string>

namespace fw
{

class Formatter
{
public:
    enum class DarkColor
    {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
    };

    enum class BrightColor
    {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
    };

    virtual std::string applyColor(const std::string& text, DarkColor color) const;
    virtual std::string applyColor(const std::string& text, BrightColor color) const;

    virtual std::string getColorCode(DarkColor color) const;
    virtual std::string getColorCode(BrightColor color) const;
    virtual std::string getResetColorCode() const;

    virtual ~Formatter() = default;
};

} // namespace fw

#endif // FW_FORMATTER_H
