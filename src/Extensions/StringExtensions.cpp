#include "StringExtensions.h"

std::vector<std::string> split(std::string text, char separator)
{
	std::vector<std::string> strings;

	for (size_t symbolIndex = 0; symbolIndex < text.length(); symbolIndex++)
	{
		size_t separatorPosition = text.find(separator);

		// If no separator character is found, the delimiter position will contain std::string::npos.
		if (separatorPosition != std::string::npos)
		{
			// Adding a substring to the vector of splitted strings starting
			// from the zero element and up to the position of the separator,
			// non-inclusive.
			strings.push_back(text.substr(0, separatorPosition));

			// Removing the already taken part of the string including separator.
			text = text.substr(separatorPosition + 1, text.length() - 1);
		}
	}

	// Adding the last splitted string.
	strings.push_back(text);

	return strings;
}

std::wstring stringToWstring(std::string text)
{
	// Creating string converter from utf-8 to utf-16 (from string to wstring).
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	// Using this converter to do all the work.
	std::wstring result = converter.from_bytes(text);

	return result;
}
