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
        dataGridView1->Columns->Clear();
        // Äîáàâëÿåì ñòîëáöû
        // Äîáàâëÿåì ñòîëáåö äëÿ íîìåðà ñòðîêè
        dataGridView1->Columns->Add("RowNumber", "#");
        dataGridView1->Columns[0]->Width = 40;
        dataGridView1->Columns->Add("Name", "Èìÿ ñ÷¸òà");
        dataGridView1->Columns->Add("Balance", "Áàëàíñ");
        dataGridView1->Columns->Add("TransactionCount", "Êîë-âî òðàíçàêöèé");
        dataGridView1->Columns->Add("Description", "Îïèñàíèå ñ÷¸òà");
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);

        if (file.is_open())
        {
            int rowNumber = 1;
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, balanceStr, count, description;

                if (std::getline(iss, name, ':')) {

                    std::istringstream nameStream(name);
                    std::string accountName;
                    std::getline(nameStream, accountName, ':');
                    if (std::getline(iss, balanceStr, ':')) {

                        std::string balanceString;
                        std::istringstream balanceStream(balanceStr);
                        std::getline(balanceStream, balanceString, ':');

                        if (std::getline(iss, count, ':'))
                        {
                            std::string countString;
                            std::istringstream countStream(count);
                            std::getline(countStream, countString, ':');
                            if (std::getline(iss, description, ','))
                            {
                                int rowIndex = dataGridView1->Rows->Add();
                                dataGridView1->Rows[rowIndex]->Cells["RowNumber"]->Value = rowNumber;
                                dataGridView1->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(accountName.c_str());
                                dataGridView1->Rows[rowIndex]->Cells["Balance"]->Value = gcnew System::String(balanceString.c_str());
                                dataGridView1->Rows[rowIndex]->Cells["TransactionCount"]->Value = gcnew System::String(countString.c_str());
                                dataGridView1->Rows[rowIndex]->Cells["Description"]->Value = gcnew System::String(description.c_str());
                                rowNumber++;
                            }
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
                std::string name, balanceStr, count, description;
                if (std::getline(iss, name, ':')) {
                    std::istringstream nameStream(name);
                    std::string currentAccountName;
                    std::getline(nameStream, currentAccountName, ':');

                    if (currentAccountName == accountName) {
                        if (std::getline(iss, balanceStr, ':'))
                        {
                            if (std::getline(iss, count, ':'))
                            {
                                if (std::getline(iss, description, ','))
                                {
                                    std::string updateLine = currentAccountName + ":" + std::to_string(GetBalanceFromTransactions(accountName)) + ":" + std::to_string(newTransactionCount) + ":" + description + ",";
                                    lines.push_back(updateLine);
                                }
                            }
                        }

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
                                            << ", type=" << typeStr << ", account=" << accountType << std::endl;//Îòëàäî÷íûé âûâîä
                                        if (accountType == accountName) {

                                            try {
                                                int amount = std::stoi(amountStr);

                                                if (typeStr == "Äîõîä") {
                                                    balance += amount;
                                                    std::cout << "Adding income: " << amount << ", current balance is " << balance << std::endl;
                                                }
                                                else if (typeStr == "Ðàñõîä")
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

        std::cout << "Starting UpdateBalancesFromTransactions" << std::endl; // Îòëàäî÷íûé âûâîä
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

    System::Void Account_TableForm::ñîçäàòüÑ÷¸òToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AccountForm^ accountForm = gcnew AccountForm();
        accountForm->ShowDialog();
        LoadAccountsToDataGridView();
        UpdateBalancesFromTransactions();
    }

    System::Void Account_TableForm::ïîêàçàòüÂñåÒðàíçàêöèèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Table_Category_TransactionForm^ Form = gcnew Table_Category_TransactionForm();
        Form->ShowDialog();
        UpdateBalancesFromTransactions();
        LoadAccountsToDataGridView();
    }


    void Account_TableForm::LoadAccountsToComboBox() {
        comboBoxAccounts->Items->Clear();
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name;
                std::string balance;
                std::string count;
                std::string description;
                if (std::getline(iss, name, ':') && std::getline(iss, balance, ':') && std::getline(iss, count, ':') && std::getline(iss, description, ','))
                {
                    std::string accountName;
                    std::istringstream nameStream(name);
                    std::getline(nameStream, accountName, ':');
                    comboBoxAccounts->Items->Add(gcnew String(accountName.c_str()));
                }
            }
            file.close();
        }
    }
    void Account_TableForm::LoadTransactionsForAccount(const std::string& accountName) {
        dataGridViewTransactions->Columns->Clear();
        dataGridViewTransactions->Columns->Add("Name", "Íàçâàíèå");
        dataGridViewTransactions->Columns->Add("Amount", "Ñóììà");
        dataGridViewTransactions->Columns->Add("Date", "Äàòà");
        dataGridViewTransactions->Columns->Add("Type", "Òèï");
        dataGridViewTransactions->Columns->Add("Category", "Êàòåãîðèÿ");
        int flag_empty = 0;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("transactions.txt"));
        std::ifstream file(filePath);

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
                                        if (accountType == accountName) {
                                            int rowIndex = dataGridViewTransactions->Rows->Add();
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(transactionName.c_str());
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Amount"]->Value = gcnew System::String(amountStr.c_str());
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Date"]->Value = gcnew System::String(dateStr.c_str());
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Type"]->Value = gcnew System::String(typeStr.c_str());
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Category"]->Value = gcnew System::String(categoryStr.c_str());
                                            flag_empty = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!flag_empty)
        {
            MessageBox::Show("Ïî âàøåìó çàïðîñó íè÷åãî íå íàéäåíî.", "Èíôîðìàöèÿ", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }
        file.close();
    }
    


    System::Void Account_TableForm::ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (table_transaction) {
            this->groupBox1->Visible = false;
            this->dataGridViewTransactions->Visible = false;
            this->buttonLoadTransactions->Visible = false;
            this->comboBoxAccounts->Visible = false;
            this->labelAccounts->Visible = false;
            table_transaction = 0;
        }
        else if (!table_transaction) {
            this->groupBox1->Visible = true;
            this->groupBox1 -> Text = "Ïîèñê òðàíçàêöèé ïî ñ÷¸òó!";
            this->dataGridViewTransactions->Visible = true;
            this->buttonLoadTransactions->Visible = true;
            this->buttonLoadTransactions->Text = "Íàéòè òðàíçàêöèè!";
            this->comboBoxAccounts->Visible = true;
            this->labelAccounts->Visible = true;
            table_transaction = 1;
        }
        
        LoadAccountsToComboBox();
        return System::Void();
    }

    System::Void Account_TableForm::buttonLoadTransactions_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (comboBoxAccounts->SelectedItem != nullptr) {
            System::String^ selectedAccount = comboBoxAccounts->SelectedItem->ToString();
            msclr::interop::marshal_context context;
            std::string accountName = context.marshal_as<std::string>(selectedAccount);
            LoadTransactionsForAccount(accountName);
        }
        return System::Void();
    }
    System::Void Account_TableForm::èíôîðìàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Áóäåò òåêñò", "Èíôîðìàöèÿ", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }
    System::Void Account_TableForm::âåðíóòüñÿÂÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
    System::Void Account_TableForm::êîíâåðòàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CurrencyConverterForm^ convert = gcnew CurrencyConverterForm();
        convert->ShowDialog();
        return System::Void();
    }
    System::Void Account_TableForm::àíàëèòèêàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AccountAnalyticsForm^ analyticsForm = gcnew AccountAnalyticsForm();
        analyticsForm->ShowDialog();
        return System::Void();
    }
}