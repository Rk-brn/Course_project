#include "MainScreen.h"
#include "GameForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Courseproject;

[STAThread]

int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	return 0;
}

System::Void Courseproject::MyForm::button_start_Click(System::Object^ sender, System::EventArgs^ e)
{
	Account_TableForm^ form1 = gcnew Account_TableForm();

	form1->ShowDialog();
	return System::Void();
}

System::Void Courseproject::MyForm::button_inf_Click(System::Object^ sender, System::EventArgs^ e)

{
	MessageBox::Show("В открывшемся окне необходимо выбрать действие с программой 'Начать работу с сервисом Фильмофонд' или 'Игра'. На кнопку выхода закрывается программы.\nПри нажатии 'Начать работу с сервисом Фильмофонд', то в данном окне необходимо выбрать режим для работы с сервисом. Для включения режима администратора следует ввести пароль. Режим пользователя и администратора отличаются доступным функционалом. В режиме пользователя доступны такие функции: 'Запрос', 'Справка' и 'Вернуться назад'.\nВ режиме администратора доступны все функции, из существующих в программе для работы с фильмами: 'Добавление записи', 'Редактирование записи', 'Удаление записи', 'Запрос', 'Очистка всего списка', 'Справка', 'Вернуться назад' и 'Сохранить записи'.\n Нажимая на 'Запрос' выполняется в отдельном окне запрос по поиску нужных фильмов по определённым категориям.\n Нажимая на 'Справка' сообщается информация о представленном окне.\nКнопка 'Вернуться назад' возвращает в главное меню программы.\nНажимая на 'Игра' запускается игровое меню змейки. Для начала игры необходимо зарегистрироваться. Игра начинается автоматически после регистрации. У змейки есть функция регулировки скорости в мс. Чем меньше мс поставит игрок, тем быстрее змейка будет двигаться.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	return System::Void();
}


System::Void Courseproject::MyForm::button_out_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void Courseproject::MyForm::button_game_Click(System::Object^ sender, System::EventArgs^ e)
{
	GameForm^ form2 = gcnew GameForm();
	form2->ShowDialog();
	return System::Void();
}
