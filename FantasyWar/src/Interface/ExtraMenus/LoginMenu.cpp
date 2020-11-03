#include "LoginMenu.h"

void LoginMenu::Show()
{
	/*
	* ���� ����
	*   ���� ���� ����� - ������ ��� ��������
	*     �� - ������ ���� ����������
	*     ��� - ������������ � ������ 1
	* ���������� ������
	*	�������� �������� 
	*     ������������� ������
	*       ����� - ����������� �������
	*       ������ - ������ ������� � ������
	*   ���������� ������
	*     ����������� �������
	*   ������������ ������
	*     ������������ � ������ ������
	*   �������� �����������
	*     ������� ��� ������������ � ������ 1
	* ���� ����������� �������
	*   ��������� ������
	*/

	bool authorizationSuccessful = false;

	while (!authorizationSuccessful)
	{
		Console::clearConsole();

		std::string nickname = Console::dialogMessage("Input your nickname");

		std::ifstream fileInput("Saves\\" + nickname + ".save");

		if (!fileInput.is_open())
		{
			std::string inputAnswer = Console::dialogMessage("It looks like there is no save file for this nickname.\n \
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
