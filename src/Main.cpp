#include <iostream>
#include <string>

#include <fmt/format.h>
#include <fmt/color.h>

//#include <windows.h>

#define GREEN_COLOR std::string("\e[1;32m")
#define RED_COLOR std::string("\e[1;31m")
#define RETURN_COLOR std::string("\e[0m")

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#endif

int main()
{
    // SetConsoleCP(65001);

    // HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // DWORD dwMode = 0;
    // GetConsoleMode(hOut, &dwMode);
    // dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    // SetConsoleMode(hOut, dwMode);

    fmt::print(fmt::format(RED_COLOR + "This is {0} language.\n" + RETURN_COLOR, "русский"));

    return 0; 
}