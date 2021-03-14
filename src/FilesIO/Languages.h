#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <regex>
#include <iostream>

#include "Console.h"
#include "Extensions/StringExtensions.h"
#include "Filesystem/Path.h"
#include "Filesystem/Filesystem.h"

namespace fw
{
	class Translations
	{
	public:
		static std::string getLanguagesFolder();

		static std::wstring translate(std::string text);

		static void changeLanguage(std::string languageName);

		static std::vector<std::string> getLanguageFilesList();
		static std::vector<std::string> getLanguagesList();

	private:
		static const std::string NO_TRANSLATION;

		static std::string _currentLanguage;

		static void addEnglishTranslation(std::string text);

		static std::string getTranslation(std::string text);
	};
}

#endif // !LANGUAGES_H
