#include "Path.h"

fw::Path::Path(std::string path) 
{
#ifdef WINDOWS
    _path = windowsPath(path);
#elif LINUX
    _path = linuxPath(path);
#endif // WINDOWS
}

std::string fw::Path::linuxPath(std::string path) 
{
    std::string resultPath = path;

    for (char& symbol : resultPath)
    {
        if (symbol == '\\') symbol = '/';
    }

    return resultPath;
}

std::string fw::Path::windowsPath(std::string path) 
{
    std::string resultPath = path;

    for (char& symbol : resultPath)
    {
        if (symbol == '/') symbol = '\\';
    }

    return resultPath;
}