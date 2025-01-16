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
	MessageBox::Show("� ����������� ���� ���������� ������� �������� � ���������� '������ ������ � �������� ����������' ��� '����'. �� ������ ������ ����������� ���������.\n��� ������� '������ ������ � �������� ����������', �� � ������ ���� ���������� ������� ����� ��� ������ � ��������. ��� ��������� ������ �������������� ������� ������ ������. ����� ������������ � �������������� ���������� ��������� ������������. � ������ ������������ �������� ����� �������: '������', '�������' � '��������� �����'.\n� ������ �������������� �������� ��� �������, �� ������������ � ��������� ��� ������ � ��������: '���������� ������', '�������������� ������', '�������� ������', '������', '������� ����� ������', '�������', '��������� �����' � '��������� ������'.\n ������� �� '������' ����������� � ��������� ���� ������ �� ������ ������ ������� �� ����������� ����������.\n ������� �� '�������' ���������� ���������� � �������������� ����.\n������ '��������� �����' ���������� � ������� ���� ���������.\n������� �� '����' ����������� ������� ���� ������. ��� ������ ���� ���������� ������������������. ���� ���������� ������������� ����� �����������. � ������ ���� ������� ����������� �������� � ��. ��� ������ �� �������� �����, ��� ������� ������ ����� ���������.", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
