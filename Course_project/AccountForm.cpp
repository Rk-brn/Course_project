#include "AccountForm.h"
#include <msclr\marshal_cppstd.h>
#include <ctime>
#include <sstream> // ��������� ������������ ���� ��� istringstream
#include <fstream>


std::vector<Account> accounts;

System::Void Courseproject::AccountForm::button_creat_account_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ nameStr = textBox_name_account->Text;
    String^ desStr = textBox_balance_account->Text;

    
    std::string name = msclr::interop::marshal_as<std::string>(nameStr);
    std::string des = msclr::interop::marshal_as<std::string>(desStr);
    int balance = 0;
    
    int countTrans = 0;
    Account newAccount(name, balance, countTrans, des);
    accounts.push_back(newAccount);
  
    std::ofstream file("account.txt", std::ios::app); // ��������� ���� � ������ ���������� (append)
    if (file.is_open()) {
        file << name << ":" << balance << ":" << countTrans << ":" << des << ",\n";
        file.close();
        MessageBox::Show("���� ������� ������ � ������� � ���� account.txt", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        MessageBox::Show("�� ������� ������� ���� ��� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    textBox_balance_account->Text = "";
    textBox_name_account->Text = "";
    return System::Void();
}
