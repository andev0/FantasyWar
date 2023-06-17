#ifndef FW_TERMINAL_H
#define FW_TERMINAL_H

#include <iostream>
#include <string>

namespace fw
{

class Terminal
{
public:
    static void print(const std::string& text);
    static void printLine(const std::string& text);
};

} // namespace fw

#endif // FW_TERMINAL_H
