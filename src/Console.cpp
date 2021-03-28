#include "Console.h"

#ifdef WINDOWS
    void fw::Console::printLine(std::string message)
    {
        std::wcout << stringToWstring(message) << L'\n';
    }
    
    std::string fw::Console::dialog(std::string message, std::vector<std::string> alternatives)
    {
        std::string answer;

        Console::printLine(message);

        for (size_t alternativeIndex = 0; alternativeIndex < alternatives.size(); alternativeIndex++)
        {
            std::string alternative = std::to_string(alternativeIndex) + ". " + 
                Translations::translate(alternatives[alternativeIndex]);

            std::wcout << stringToWstring(alternative) << L'\n';
        }

        std::wcout << L"\n> ";

        std::cin >> answer;

        return answer;
    }
#else
    void fw::Console::printLine(std::string message)
    {
        std::cout << message << '\n';
    }
    
    std::string fw::Console::dialog(std::string message, std::vector<std::string> alternatives)
    {
        std::string answer;

        Console::printLine(message);

        for (size_t alternativeIndex = 0; alternativeIndex < alternatives.size(); alternativeIndex++)
        {
            std::string alternative = std::to_string(alternativeIndex) + ". " + 
                Translations::translate(alternatives[alternativeIndex]);
                
            std::cout << alternative << '\n';
        }

        std::cout << "\n> ";

        std::cin >> answer;

        return answer;
    }
#endif // WINDOWS

#ifdef DEBUG
    void fw::Console::debugPrint(std::string message)
    {
        #ifdef WINDOWS
            std::wcout << stringToWstring(message) << L'\n';
        #else
            std::cout << message << '\n';
        #endif // WINDOWS
    }
#else
    void fw::Console::debugPrint(std::string message)
    {
        // No debug print in release builds.
    }
#endif // DEBUG

#ifdef WINDOWS
    void fw::Console::clear()
    {
        std::system("cls");
    }
#elif LINUX
    void fw::Console::clear()
    {
        std::system("clear");
    }
#endif

void fw::Console::pause(std::string message)
{
    if (message != "")
    {
        Console::printLine(message);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

std::string fw::Console::makeTitle(std::string text) 
{
    return "> " + fw::Translations::translate(text) + " <";
}