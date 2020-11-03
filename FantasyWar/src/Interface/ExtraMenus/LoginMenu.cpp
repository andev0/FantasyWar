#include "LoginMenu.h"

void LoginMenu::Show()
{
	/*
	* Ввод ника
	*   Если нету файла - вопрос про создание
	*     Да - создаём файл сохранения
	*     Нет - возвращаемся к пункту 1
	* Спрашиваем пароль
	*	Создание аккаунта 
	*     Подтверждение пароля
	*       Удача - Авторизация успешна
	*       Провал - Повтор вопроса о пароле
	*   Правильный пароль
	*     Авторизация успешна
	*   Неправильный пароль
	*     Возвращаемся к спросу пароля
	*   Отменили авторизацию
	*     Выходим или возвращаемся к пункту 1
	* Если авторизация успешна
	*   Загружаем данные
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
