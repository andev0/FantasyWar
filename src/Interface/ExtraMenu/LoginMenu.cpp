#include "LoginMenu.h"

void fw::LoginMenu::Show()
{
	bool authorizationSuccessful = false;

	while (!authorizationSuccessful)
	{
		Console::clear();

		// TODO: remake all this menu.

		std::string nickname = Console::dialog("Input your nickname");

		std::ifstream fileInput("Saves\\" + nickname + ".save");

		if (!fileInput.is_open())
		{
			std::string inputAnswer = Console::dialog("It looks like there is no save file for this nickname.\n \
															  Do you want to create character?",
															  { "Yes (Create character).", "No (Enter other nickname)" });

			if (inputAnswer == "1")
			{
				// Save data to "Saves\\" + nickname + ".save"
			}
			else
			{
				continue;
			}
		}
	}
}
