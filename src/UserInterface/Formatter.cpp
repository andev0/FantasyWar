#include "Formatter.h"

namespace fw
{
std::string Formatter::applyColor(const std::string& text, DarkColor color)
{
    return getColorCode(color) + text + getResetColorCode();
}

std::string Formatter::applyColor(const std::string& text, BrightColor color)
{
    return getColorCode(color) + text + getResetColorCode();
}

std::string Formatter::getColorCode(DarkColor color)
{
    return std::string("\033[3") + (char)('0' + (char)color) + 'm';
}

std::string Formatter::getColorCode(BrightColor color)
{
    return std::string("\033[9") + (char)('0' + (char)color) + 'm';
}

std::string Formatter::getResetColorCode()
{
    return "\033[0m";
}
} // namespace fw
