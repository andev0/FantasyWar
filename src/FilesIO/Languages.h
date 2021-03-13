#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <regex>
#include <iostream>

#include "Extensions/StringExtensions.h"

class Languages
{
public:
	static std::string LANGUAGES_FOLDER;

	static std::wstring translate(std::string text);

	static void changeLanguage(std::string languageName);

	static std::vector<std::string> getLanguageFilesList();
	
	static std::vector<std::string> getLanguagesList();

private:
	static std::string _currentLanguage;

	static void addEnglishTranslation(std::string text);

	static std::string getTranslation(std::string text);
};

#endif // !LANGUAGES_H
