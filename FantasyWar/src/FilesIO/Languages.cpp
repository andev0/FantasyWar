#include "Languages.h"

std::string	Languages::LANGUAGES_FOLDER = "Languages/";

std::vector<std::string> Languages::getLanguageFilesList()
{
    std::vector<std::string> filesPaths;

    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path().string() + "/" + LANGUAGES_FOLDER))
    {
        filesPaths.push_back(entry.path().string());
    }

    return filesPaths;
}

std::vector<std::string> Languages::getLanguagesList()
{
    std::vector<std::string> filesPaths = Languages::getLanguageFilesList();

    std::vector<std::string> languageNames;
    


    return languageNames;
}
