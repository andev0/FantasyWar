#ifndef FW_PATH_H
#define FW_PATH_H

#include <string>

namespace fw 
{
    // Class for crossplatform passes
    class Path 
    {
    public:
        Path(std::string path);

        operator std::string() { return _path; };

        std::string linuxPath(std::string path);
        std::string windowsPath(std::string path);

    private:
        std::string _path;
    };
}

#endif // FW_PATH_H