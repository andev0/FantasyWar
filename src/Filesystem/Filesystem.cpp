#include "Filesystem.h"

std::string fw::Filesystem::_gamePath = "";

void fw::Filesystem::setGamePath(const char* path) 
{
    _gamePath = Path(path);
}

std::string fw::Filesystem::getGamePath() 
{
    if (_gamePath == "")
    {
        fw::Console::print(fw::Translations::translate("Error: Filesystem::_gamePath not set."));
    }
    return _gamePath;
}

std::string fw::Filesystem::getGameFolderPath() 
{
    for (int i = _gamePath.size() - 1; i >= 0; i--)
    {
        if (_gamePath[i] == '\\' || _gamePath[i] == '/')
        {
            return _gamePath.substr(0, i + 1);
        }
    }

    return ".";
}
