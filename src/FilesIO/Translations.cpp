#include "Translations.h"

namespace fs = std::filesystem;
using namespace fw;

const std::string Translations::NO_TRANSLATION = "@";

std::string Translations::_currentLanguage = "English";

std::string Translations::getLanguagesFolder()
{
    return Path(Filesystem::getGameFolderPath() + "Languages\\");
}

// Function for translating text to current game's language.
// If translation file not contains needed string so function will return
// recieved argument.
std::string Translations::translate(std::string text)
{
    addEnglishTranslation(text);

    std::string translation = getTranslation(text);

    if (_currentLanguage == "English" || translation == NO_TRANSLATION)
    {
        return text;
    }
    else
    {
        return translation;
    }
}

void Translations::changeLanguage(std::string languageName)
{
    std::ifstream fileIn(getLanguagesFolder() + languageName + ".lang", std::ios_base::binary);
    
    if (fileIn.is_open())
    {
        std::string line;

        getline(fileIn, line);

        // If file contains language code (e.g. "en") on the first line.
        if (std::regex_match(line, std::regex("^([a-zA-Z]{2})$")))
        {
            // So switching locale to the required using a language code from file.
            setlocale(LC_ALL, line.c_str());
            _currentLanguage = languageName;
        }
        else
        {
            Console::print(fw::Translations::translate("Wrong translation file format. Language code is missing or incorrect."));
        }

        fileIn.close();
    }
    else
    {
        Console::print(fw::Translations::translate("Can't open translation file."));
    }
}

std::vector<std::string> Translations::getTranslationsPathes()
{
    std::vector<std::string> filesPaths;

    // Iterating over the directory's entries to get paths of all files in the 
    // Languages folder.
    for (auto& entry : fs::directory_iterator(getLanguagesFolder()))
    {
        filesPaths.push_back(entry.path().string());
    }

    return filesPaths;
}

std::vector<std::string> Translations::getLanguagesList()
{
    std::vector<std::string> languageNames;
    
    // Splitting all of the translation files by the '\' separator.
    // Then getting Language name by cutting the file extension.
    for (std::string& filePath : getTranslationsPathes())
    {
        std::vector<std::string> splittedPath = split(filePath, '\\');
        languageNames.push_back(split(splittedPath.at(splittedPath.size() - 1), '.')[0]);
    }

    return languageNames;
}

// Function for adding new English string translation into the English.lang file.
void Translations::addEnglishTranslation(std::string text)
{
    std::string langFilePath = getLanguagesFolder() + "English.lang";
    std::ifstream fileIn(langFilePath, std::ios_base::binary);

    // Searching for argument string in the English translation file.
    // If it is found so it's nothing to do.
    if (fileIn.is_open())
    {
        std::string line;
        while (getline(fileIn, line))
        {
            if (line == text)
            {
                fileIn.close();
                return;
            }
        }

        fileIn.close();
    }

    std::ofstream fileOut(langFilePath, std::ios_base::app | std::ios_base::binary);

    // If argument string don't exist in the English translation file so we just add it.
    if (fileOut.is_open())
    {
        fileOut << '\n' << text << '\n';
    }

    fileOut.close();
}

std::string Translations::getTranslation(std::string text)
{
    std::string langFilePath = getLanguagesFolder() + _currentLanguage + ".lang";
    std::ifstream fileIn(langFilePath, std::ios_base::binary);

    // Searching for line in English in the translation file.
    if (fileIn.is_open())
    {
        std::string line;

        while (getline(fileIn, line))
        {
            // If line in English is found so we looking to the next line.
            if (line == text)
            {
                getline(fileIn, line);
                
                return line;
            }
        }
    }

    fileIn.close();

    std::ofstream fileOut(langFilePath, std::ios_base::app | std::ios_base::binary);

    // If string to translate isn't exist so adding it on English and NO_TRANSLATION in the next line.
    if (fileOut.is_open())
    {
        fileOut << '\n' << text << '\n' << NO_TRANSLATION << '\n';
    }

    fileOut.close();

    // Returning empty string if translation wasn't found.
    return NO_TRANSLATION;
}
