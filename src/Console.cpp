#include "Console.h"

void fw::Console::print(std::string message)
{
#ifdef WINDOWS
	std::wcout << stringToWstring(message) << L'\n';
#else
	std::cout << message << '\n';
#endif // WINDOWS
}

void fw::Console::debugPrint(std::string message)
{
#ifdef DEBUG
#ifdef WINDOWS
	std::wcout << stringToWstring(message) << L'\n';
#else
	std::cout << message << '\n';
#endif // WINDOWS
#endif // DEBUG
}

std::string fw::Console::dialog(std::string message, std::vector<std::string> alternatives)
{
	std::string answer;

	Console::print(message);

	for (size_t alternativeIndex = 0; alternativeIndex < alternatives.size(); alternativeIndex++)
	{
		std::string alternative = std::to_string(alternativeIndex) + ". " + 
			Translations::translate(alternatives[alternativeIndex]);
#ifdef WINDOWS
		std::wcout << stringToWstring(alternative) << L'\n';
#else
		std::cout << alternative << '\n';
#endif // WINDOWS
	}

#ifdef WINDOWS
		std::wcout << L"\n> ";
#else
		std::cout << "\n> ";
#endif // WINDOWS

	std::cin >> answer;

	return answer;
}

void fw::Console::clear()
{
#if _WINDOWS
	std::system("cls");
#elif _LINUX
	std::system("clear");
#endif
}

void fw::Console::pause(std::string message)
{
	if (message != "")
	{
		Console::print(message);
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}
