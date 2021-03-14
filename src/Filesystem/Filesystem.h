#ifndef FW_FILESYSTEM_H
#define FW_FILESYSTEM_H

#include <string>

#include "Extensions/StringExtensions.h"
#include "Filesystem/Path.h"
#include "Console.h"

namespace fw
{
    class Filesystem
    {
    public:
        static void setGamePath(const char* path);
        static std::string getGamePath();
        static std::string getGameFolderPath();

    private:
        static std::string _gamePath;
    };
}

#endif // FW_FILESYSTEM_H