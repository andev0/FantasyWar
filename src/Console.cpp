#include "Console.h"

void fw::Console::print(std::string message)
{
	std::wcout << Translations::translate(message) << L"\n";
}

void fw::Console::debugPrint(std::string message)
{
#ifdef DEBUG
	std::cout << message << "\n";
#endif // DEBUG
}

std::string fw::Console::dialog(std::string message, std::vector<std::string> alternatives)
{
	std::string answer;

	Console::print(message);

	for (size_t alternativeIndex = 0; alternativeIndex < alternatives.size(); alternativeIndex++)
	{
		std::wcout << alternativeIndex << L". " << Translations::translate(alternatives[alternativeIndex]) << L"\n";
	}

	std::wcout << L"\n> ";

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
