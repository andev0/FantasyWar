#ifndef FW_TERMINAL_H
#define FW_TERMINAL_H

#include <iostream>
#include <string>
#include <assert.h>

#include "MenuItems/TitleMenuItem.h"
#include "MenuItems/InputMenuItem.h"
#include "Menus/Menu.h"

#include "UserInterface/Formatter.h"

namespace fw
{

class Terminal
{
public:
    static void print(const std::string& text);
    static void printLine(const std::string& text = "");

    static void display(MenuItem* menuItem);
    static void display(const Menu* menu);

    // Returns false if menu stack is empty.
    static bool displayTopmostMenu();

    static void pushMenuStack(const Menu* menu);
    static void popMenuStack();

    static void notify(const std::string& text);

    static std::string readLine();

    static void clear();

private:
    static inline std::stack<const Menu*> m_menuStack {};

    static inline Formatter m_formatter {};

    static void processInput(const Menu* menu, const std::string& input);
};

} // namespace fw

#endif // FW_TERMINAL_H
