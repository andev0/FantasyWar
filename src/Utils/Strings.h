#ifndef FW_STRINGS_H
#define FW_STRINGS_H

#include <sstream>

namespace fw
{

#define STRING(stream) (std::stringstream() << stream).str()

template<class T>
T stringTo(const std::string& str)
{
    std::stringstream stream(str);

    T result;
    stream >> result;

    return result;
}

} // namespace fw

#endif // FW_STRINGS_H