#include "Account_TableForm.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Courseproject {
    Account_TableForm::Account_TableForm(void)
    {
        InitializeComponent();
        LoadAccountsToDataGridView();
        UpdateBalancesFromTransactions();
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
                std::string name, balanceStr, count;

                if (std::getline(iss, name, ':')) {

                    std::istringstream nameStream(name);
                    std::string accountName;
                    std::getline(nameStream, accountName, ':');
                    if (std::getline(iss, balanceStr, ':')) {

                        std::string balanceString;
                        std::istringstream balanceStream(balanceStr);
                        std::getline(balanceStream, balanceString, ':');

                        if (std::getline(iss, count, ',')) {

                            std::string countString;
                            std::istringstream countStream(count);
                            std::getline(countStream, countString, ':');

                            int rowIndex = dataGridView1->Rows->Add();
                            dataGridView1->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(accountName.c_str());
                            dataGridView1->Rows[rowIndex]->Cells["Balance"]->Value = gcnew System::String(balanceString.c_str());
                            dataGridView1->Rows[rowIndex]->Cells["TransactionCount"]->Value = gcnew System::String(countString.c_str());
                        }
                    }
                }
            }
            file.close();
        }
    }


    void Account_TableForm::UpdateAccountData(const std::string& accountName, int newTransactionCount) {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        std::vector<std::string> lines;

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, balanceStr, count;
                if (std::getline(iss, name, ':')) {
                    std::istringstream nameStream(name);
                    std::string currentAccountName;
                    std::getline(nameStream, currentAccountName, ':');

                    if (currentAccountName == accountName) {

                        std::string updateLine = currentAccountName + ":" + std::to_string(GetBalanceFromTransactions(accountName)) + ":" + std::to_string(newTransactionCount) + ",";
                        lines.push_back(updateLine);
                    }
                    else {
                        lines.push_back(line);
                    }
                }
                else {
                    lines.push_back(line);
                }
            }
            file.close();
        }
        std::ofstream outFile(filePath);
        if (outFile.is_open()) {
            for (const auto& line : lines) {
                outFile << line << std::endl;
            }
            outFile.close();
        }

    }

    int Account_TableForm::GetBalanceFromTransactions(const std::string& accountName) {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("transactions.txt"));
        std::ifstream file(filePath);

        int balance = 0;
        std::cout << "Start processing transactions for account: " << accountName << std::endl;
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string transactionName, amountStr, dateStr, typeStr, categoryStr, accountType;
                if (std::getline(iss, transactionName, ';'))
                {
                    if (std::getline(iss, amountStr, ';')) {
                        if (std::getline(iss, dateStr, ';')) {
                            if (std::getline(iss, typeStr, ';')) {
                                if (std::getline(iss, categoryStr, ';'))
                                {
                                    if (std::getline(iss, accountType, ';'))
                                    {
                                        std::cout << "Transaction: name=" << transactionName << ", amount=" << amountStr
                                            << ", type=" << typeStr << ", account=" << accountType << std::endl;//Отладочный вывод
                                        if (accountType == accountName) {

                                            try {
                                                int amount = std::stoi(amountStr);

                                                if (typeStr == "Доход") {
                                                    balance += amount;
                                                    std::cout << "Adding income: " << amount << ", current balance is " << balance << std::endl;
                                                }
                                                else if (typeStr == "Расход")
                                                {
                                                    balance -= amount;
                                                    std::cout << "Subtracting expense: " << amount << ", current balance is " << balance << std::endl;
                                                }
                                            }
                                            catch (const std::invalid_argument& e)
                                            {
                                                std::cerr << "Error parsing amount in transaction: " << amountStr << std::endl;
                                            }
                                            catch (const std::out_of_range& e)
                                            {
                                                std::cerr << "Error number out of range: " << amountStr << std::endl;
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            file.close();
        }
        std::cout << "Final balance for " << accountName << " is: " << balance << std::endl;
        return balance;
    }

    void Account_TableForm::UpdateBalancesFromTransactions() {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        std::vector<std::string> accounts;

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string accountName, balanceStr, countStr;
                if (std::getline(iss, accountName, ':'))
                {
                    std::istringstream nameStream(accountName);
                    std::string currentAccountName;
                    std::getline(nameStream, currentAccountName, ':');
                    accounts.push_back(currentAccountName);
                }

            }
            file.close();
        }

        std::cout << "Starting UpdateBalancesFromTransactions" << std::endl; // Отладочный вывод
        for (const auto& accountName : accounts) {

            int newBalance = GetBalanceFromTransactions(accountName);
            std::cout << "New balance calculated for " << accountName << ": " << newBalance << std::endl;
            int newTransactionCount = 0;

            msclr::interop::marshal_context context1;
            std::string filePath1 = context1.marshal_as<std::string>(gcnew System::String("transactions.txt"));
            std::ifstream file1(filePath1);
            if (file1.is_open())
            {
                std::string line;
                while (std::getline(file1, line))
                {
                    std::istringstream iss(line);
                    std::string transactionName, amountStr, dateStr, typeStr, categoryStr, accountType;
                    if (std::getline(iss, transactionName, ';'))
                    {
                        if (std::getline(iss, amountStr, ';')) {
                            if (std::getline(iss, dateStr, ';')) {
                                if (std::getline(iss, typeStr, ';')) {
                                    if (std::getline(iss, categoryStr, ';'))
                                    {
                                        if (std::getline(iss, accountType, ';'))
                                        {
                                            if (accountType == accountName) {
                                                std::cout << "Found transaction for " << accountName << ": name=" << transactionName << std::endl;
                                                newTransactionCount++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            file1.close();
            std::cout << "Updating account data for " << accountName << ", transaction count is " << newTransactionCount << std::endl;
            UpdateAccountData(accountName, newTransactionCount);
        }
    }

    System::Void Account_TableForm::создатьСчётToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AccountForm^ accountForm = gcnew AccountForm();
        accountForm->ShowDialog();
        LoadAccountsToDataGridView();
        UpdateBalancesFromTransactions();
    }

    System::Void Account_TableForm::показатьВсеТранзакцииToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Table_Category_TransactionForm^ Form = gcnew Table_Category_TransactionForm();
        Form->ShowDialog();
        UpdateBalancesFromTransactions();
        LoadAccountsToDataGridView();
    }

}