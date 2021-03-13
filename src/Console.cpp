#include "Console.h"

void fw::Console::printMessage(std::string message)
{
	std::wcout << Languages::translate(message) << "\n";
}

void fw::Console::debugPrint(std::string message)
{
#ifdef DEBUG
	std::cout << message << "\n";
#endif // DEBUG
}

std::string fw::Console::dialogMessage(std::string message, std::vector<std::string> alternatives)
{
	std::string answer;

	std::wcout << Languages::translate(message) << "\n";

	for (size_t alternativeIndex = 0; alternativeIndex < alternatives.size(); alternativeIndex++)
	{
		std::wcout << alternativeIndex << L". " << Languages::translate(alternatives[alternativeIndex]) << L"\n";
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
		std::cout << message << std::endl;
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}
