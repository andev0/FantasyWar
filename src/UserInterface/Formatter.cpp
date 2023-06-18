#include "Formatter.h"

namespace fw
{
std::string Formatter::applyColor(const std::string& text, DarkColor color)
{
    return std::string("\033[3") + (char)('0' + (char)color) + 'm' + text + "\033[0m";
}

std::string Formatter::applyColor(const std::string& text, BrightColor color)
{
    return std::string("\033[9") + (char)('0' + (char)color) + 'm' + text + "\033[0m";
}
} // namespace fw
