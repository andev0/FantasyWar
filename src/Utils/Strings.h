#ifndef FW_STRINGS_H
#define FW_STRINGS_H

#include <sstream>
#include <exception>
#include <boost/type_index.hpp>

namespace fw
{

/// Allows to easily create a string using stringstream capabilities.
#define STRING(stream) (std::stringstream() << stream).str()

/// Converts @param str to type @tparam T.
/// @throws invalid_argument exception if there is no possible conversion.
template<class T>
T stringTo(const std::string& str)
{
    std::stringstream stream(str);

    T result;
    stream >> result;

    if (stream.fail())
    {
        throw std::invalid_argument(
            STRING("\"" << str << "\" can't be converted to "
                        << boost::typeindex::type_id<T>().pretty_name()));
    }

    return result;
}

} // namespace fw

#endif // FW_STRINGS_H