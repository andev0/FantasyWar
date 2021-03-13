#include "Languages.h"

namespace fs = std::filesystem;

// Folder with .lang files for importing translations.
std::string	fw::Languages::LANGUAGES_FOLDER = "Languages\\";

std::string fw::Languages::_currentLanguage = "English";

// Function for translating text to current game's language.
// If translation file not contains needed string so function will return
// recieved argument.
std::wstring fw::Languages::translate(std::string text)
{
    std::string langFilePath = LANGUAGES_FOLDER + _currentLanguage + ".lang";

    addEnglishTranslation(text);

    // If current language is English so no need to translate anything so just
    // returning text argument.
    if (_currentLanguage == "English")
    {
        return stringToWstring(text);
    }

    // Getting translation of text to current game language.
    // If there is no translation, just returning text argument.
    std::string translation = getTranslation(text);
    if (translation != "")
    {
        return stringToWstring(translation);
    }
    else
    {
        return stringToWstring(text);
    }
}

void fw::Languages::changeLanguage(std::string languageName)
{
    for (std::string& language : getLanguagesList())
    {
        // If the required translation file is found.
        if (languageName == language)
        {
            std::string langFilePath = LANGUAGES_FOLDER + language + ".lang";
            std::ifstream fileIn(langFilePath);

            if (fileIn.is_open())
            {
                std::string line;

                getline(fileIn, line);

                std::regex languageCodeRegex("([a-zA-Z]{2})", std::regex::ECMAScript);

                // If file contains language code (e.g. "en") on the first line.
                if (std::regex_match(line.begin(), line.end(), languageCodeRegex))
                {
                    // So switching locale to the required using a language code from file.
                    setlocale(LC_ALL, line.c_str());
                    _currentLanguage = languageName;
                }
            }

            fileIn.close();

            return;
        }
    }
}

std::vector<std::string> fw::Languages::getLanguageFilesList()
{
    std::vector<std::string> filesPaths;
    std::string filesPath = fs::current_path().string() + "\\" + LANGUAGES_FOLDER;

    // Iterating over the directory's entries to get paths of all files in the 
    // Languages folder.
    for (auto& entry : fs::directory_iterator(filesPath))
    {
        filesPaths.push_back(entry.path().string());
    }

    return filesPaths;
}

std::vector<std::string> fw::Languages::getLanguagesList()
{
    std::vector<std::string> filesPaths = Languages::getLanguageFilesList();

    std::vector<std::string> languageNames;
    
    // Splitting all of the translation files by the '\' separator.
    // Then getting Language name by cutting the file extension.
    for (std::string& filePath : filesPaths)
    {
        std::vector<std::string> splittedPath = split(filePath, '\\');
        languageNames.push_back(split(splittedPath.at(splittedPath.size() - 1), '.')[0]);
    }

    return languageNames;
}

// Function for adding new English string translation into the English.lang file.
void fw::Languages::addEnglishTranslation(std::string text)
{
    std::string langFilePath = LANGUAGES_FOLDER + "English.lang";
    std::ifstream fileIn(langFilePath);

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
    }

    fileIn.close();

    std::ofstream fileOut(langFilePath, std::ios_base::app);

    // If argument string don't exist in the English translation file so we just add it.
    if (fileOut.is_open())
    {
        fileOut << text << "\n\n";
    }

    fileOut.close();
}

std::string fw::Languages::getTranslation(std::string text)
{
    std::string langFilePath = LANGUAGES_FOLDER + _currentLanguage + ".lang";
    std::ifstream fileIn(langFilePath);

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
                if (line != "@") // @ means that translation isn't exist.
                {
                    // Returning translated string from file.
                    return line;
                }
                
                return "";
            }
        }
    }

    fileIn.close();

    std::ofstream fileOut(langFilePath, std::ios_base::app);

    // If string to translate isn't exist so adding it on English and @ in the next line.
    if (fileOut.is_open())
    {
        fileOut << text << "\n@\n"; // @ means that translation isn't exist.
    }

    fileOut.close();

    // Returning empty string if translation wasn't found.
    return "";
}
