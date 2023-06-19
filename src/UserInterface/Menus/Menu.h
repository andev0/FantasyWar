#ifndef FW_MENU_H
#define FW_MENU_H

#include <vector>
#include <memory>

#include "UserInterface/MenuItems/TitleMenuItem.h"
#include "Action.h"
#include "Command.h"

namespace fw
{

class Menu
{
public:
    Menu() = default;
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

    virtual ~Menu() = default;

    const std::vector<std::unique_ptr<MenuItem>>& getMenuItems() const;
    const std::vector<Action>& getMenuOptions() const;
    const std::vector<Command>& getCommands() const;

protected:
    void addMenuItem(std::unique_ptr<MenuItem> menuItem);

    void addMenuOption(const Action& menuOption);
    void addMenuOption(
        const std::string& name = "", const std::function<void()>& action = [] {});

    void addCommand(const Command& command);
    void addCommand(const std::string& pattern, const std::function<void()>& action);

private:
    std::vector<std::unique_ptr<MenuItem>> m_menuItems;
    std::vector<Action> m_actions;
    std::vector<Command> m_commands;
};

} // namespace fw

#endif // FW_MENU_H