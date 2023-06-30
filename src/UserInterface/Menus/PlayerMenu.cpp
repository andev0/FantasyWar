#include "PlayerMenu.h"

#include "UserInterface/MenuItems/DynamicTextMenuItem.h"
#include "Game/Player.h"

#include "UserInterface/MenuItems/PauseMenuItem.h"

namespace fw
{

const PlayerMenu& PlayerMenu::getInstance()
{
    static const PlayerMenu instance;

    return instance;
}

PlayerMenu::UpgradeMenu::UpgradeMenu(const std::string& skillName, size_t& skillToUpgrade)
{
    addMenuItem(std::make_unique<TitleMenuItem>("Skill upgrading"));

    addMenuItem(std::make_unique<TextMenuItem>(
        std::string("How many skill points do you want to spend on ") + skillName + "?"));
    addMenuItem(
        std::make_unique<TextMenuItem>("Enter \"0\" to go back to the previous menu."));

    auto* skillPointsCountItem = new InputMenuItem();

    addMenuItem(std::unique_ptr<InputMenuItem>(skillPointsCountItem));

    skillPointsCountItem->invokeOnResultSet(
        [&skillToUpgrade, &skillName](const std::string& input) {
            if (input != "0")
            {
                using Color = Formatter::BrightColor;

                auto amount = stoul(input);

                if (Player::getInstance().getSkillPointsAmount() >= amount)
                {
                    skillToUpgrade += amount;
                    Player::getInstance().spendSkillPoints(amount);

                    Terminal::notify(Terminal::getFormatter().applyColor(
                        std::string("\n") + skillName + " upgraded successfully.\n",
                        Color::YELLOW));
                }
                else
                {
                    Terminal::notify(Terminal::getFormatter().applyColor(
                        std::string("\nYou haven't ") + input + " skill points.\n",
                        Color::RED));
                }
            }
        });
}

PlayerMenu::PlayerMenu()
{
    addMenuItem(std::make_unique<TitleMenuItem>("Player"));

    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return Player::getInstance().getNickname() + " ("
               + std::to_string(Player::getInstance().getLevel()) + " lvl)";
    }));
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Damage: ")
               + std::to_string(Player::getInstance().getDamage());
    }));
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Health: ") + std::to_string(Player::getInstance().getHealth())
               + "/" + std::to_string(Player::getInstance().getMaxHealth());
    }));
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Gold: ")
               + std::to_string(Player::getInstance().getGoldAmount());
    }));
    addMenuItem(std::make_unique<DynamicTextMenuItem>([] {
        return std::string("Skill points: ")
               + std::to_string(Player::getInstance().getSkillPointsAmount());
    }));

    addMenuOption("Back", fw::Terminal::popMenuStack);
    addMenuOption("Upgrade damage", []() {
        UpgradeMenu upgradeDamageMenu("Damage", Player::getInstance().m_damage);
        Terminal::display(&upgradeDamageMenu);
    });
    addMenuOption("Upgrade max health", []() {
        UpgradeMenu upgradeMaxHealthMenu("Maximum health",
                                         Player::getInstance().m_maxHealth);
        Terminal::display(&upgradeMaxHealthMenu);
    });
}

} // namespace fw
