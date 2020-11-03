#pragma once

#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

class Languages
{
public:
	static std::string LANGUAGES_FOLDER;

	static std::vector<std::string> getLanguageFilesList();
	static std::vector<std::string> getLanguagesList();
};

#endif // !LANGUAGES_H
