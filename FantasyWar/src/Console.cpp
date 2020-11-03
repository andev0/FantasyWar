#include "Console.h"

std::string Console::dialogMessage(std::string message, std::vector<std::string> alternatives)
{
	std::string answer;

	std::cout << message << "\n";

	for (size_t alternativeIndex = 0; alternativeIndex < alternatives.size(); alternativeIndex++)
	{
		std::cout << alternativeIndex << ". " << alternatives[alternativeIndex] << "\n";
	}

	std::cout << "\n> ";

	std::cin >> answer;

	return answer;
}

void Console::clearConsole()
{
#ifdef WINDOWS
	std::system("cls");
#else
	std::system("clear");
#endif
}
