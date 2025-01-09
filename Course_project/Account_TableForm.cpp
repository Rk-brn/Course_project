#include "Account_TableForm.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <sstream>

namespace Courseproject {
    Account_TableForm::Account_TableForm(void)
    {
        InitializeComponent();
        LoadAccountsToDataGridView();
        //
        //TODO: добавьте код конструктора
        //
    }
    void Account_TableForm::LoadAccountsToDataGridView() {
        // Очищаем предыдущие столбцы (если есть)
        dataGridView1->Columns->Clear();
        // Добавляем столбцы
        dataGridView1->Columns->Add("Name", "Имя счёта");
        dataGridView1->Columns->Add("Balance", "Баланс");
        dataGridView1->Columns->Add("TransactionCount", "Кол-во транзакций");

        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, balanceStr;

                if (std::getline(iss, name, ':')) {

                    std::istringstream nameStream(name);
                    std::string accountName;
                    std::getline(nameStream, accountName, ' ');
                    if (std::getline(iss, balanceStr, ',')) {

                        std::string balanceString;
                        std::istringstream balanceStream(balanceStr);
                        std::getline(balanceStream, balanceString, ':');

                        // Поиск аккаунта в векторе accounts по имени
                        int transactionCount = 0;
                        for (const auto& account : accounts)
                        {
                            if (account.getName() == accountName)
                            {
                                transactionCount = account.getTransactionCount();
                                break;
                            }
                        }

                        int rowIndex = dataGridView1->Rows->Add();
                        dataGridView1->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(accountName.c_str());
                        dataGridView1->Rows[rowIndex]->Cells["Balance"]->Value = gcnew System::String(balanceString.c_str());
                        dataGridView1->Rows[rowIndex]->Cells["TransactionCount"]->Value = transactionCount; 
                    }
                }
            }
            file.close();
        }
    }
    System::Void Account_TableForm::создатьСчётToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AccountForm^ accountForm = gcnew AccountForm();
        accountForm->ShowDialog();
        LoadAccountsToDataGridView();
    }

    System::Void Account_TableForm::показатьВсеТранзакцииToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Table_Category_TransactionForm^ Form = gcnew Table_Category_TransactionForm();
        Form->ShowDialog();
    }

}