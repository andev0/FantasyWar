#ifndef FW_STRINGS_H
#define FW_STRINGS_H

#include <sstream>

namespace fw
{

#define STRING(stream) (std::stringstream() << stream).str()

} // namespace fw

#endif // FW_STRINGS_H