#include "Terminal.h"

namespace fw
{

void Terminal::print(const std::string& text)
{
    std::cout << text;
}

void Terminal::printLine(const std::string& text)
{
    std::cout << text << std::endl;
}

} // namespace fw
