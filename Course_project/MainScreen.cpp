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
	MessageBox::Show("Добро пожаловать в главное меню финансового приложения!\n\nЗдесь вы можете:\n- Начать работу с финансами: управлять счетами, транзакциями, валютами и просматривать аналитику.\n- Развлечься в игре 'Змейка': интересная и захватывающая игра.\n\nПри работе с финансами, вы сможете:\n- Создавать и редактировать счета и транзакции.\n- Конвертировать балансы счетов между разными валютами.\n- Просматривать аналитику по вашим счетам.\n- Управлять валютами и их курсами.\n\nПриятного использования!", "Информация о приложении", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
