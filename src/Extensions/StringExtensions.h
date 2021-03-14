#ifndef FW_EXTENSIONS_H
#define FW_EXTENSIONS_H

#include <string>
#include <vector>
// For converting multi-byte text to wide string.
#include <codecvt>

namespace fw
{
    std::vector<std::string> split(std::string text, char separator = ' ');

    std::wstring stringToWstring(std::string text);
}

#endif // !FW_EXTENSIONS_H
