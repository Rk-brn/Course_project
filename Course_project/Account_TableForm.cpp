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
        // Добавляем столбцы
        // Добавляем столбец для номера строки
        dataGridView1->Columns->Add("RowNumber", "#");
        dataGridView1->Columns[0]->Width = 40;
        dataGridView1->Columns->Add("Name", "Имя счёта");
        dataGridView1->Columns->Add("Balance", "Баланс");
        dataGridView1->Columns->Add("TransactionCount", "Кол-во транзакций");
        dataGridView1->Columns->Add("Description", "Описание счёта");
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        int flag_rowNumber = 0;
        if (file.is_open())
        {
            int rowNumber = 0;
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
                                rowNumber++;
                                double balance = std::stod(balanceStr) / 100.0;
                                System::String^ formattedBalance = String::Format("{0:F2}", balance);
                                int rowIndex = dataGridView1->Rows->Add();
                                dataGridView1->Rows[rowIndex]->Cells["RowNumber"]->Value = rowNumber;
                                dataGridView1->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(accountName.c_str());
                                dataGridView1->Rows[rowIndex]->Cells["Balance"]->Value = formattedBalance;
                                dataGridView1->Rows[rowIndex]->Cells["TransactionCount"]->Value = gcnew System::String(countString.c_str());
                                dataGridView1->Rows[rowIndex]->Cells["Description"]->Value = gcnew System::String(description.c_str());
                                flag_rowNumber = 1;
                            }
                        }
                    }
                }
                
            }
            file.close();
        }
        
        if (flag_rowNumber == 1) {
            this->просмотрТранзакцийToolStripMenuItem->Enabled = true;
        }
        if (flag_rowNumber == 0) { this->просмотрТранзакцийToolStripMenuItem->Enabled = false; }
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

    System::Void Account_TableForm::создатьСчётToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
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


    void Account_TableForm::UpdateTransactionAccount(const std::string& oldAccountName, const std::string& newAccountName, bool updateAll)
    {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("transactions.txt"));
        std::ifstream file(filePath);
        std::vector<std::string> lines;

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string transactionName, amountStr, dateStr, typeStr, categoryStr, accountType;
                if (std::getline(iss, transactionName, ';') &&
                    std::getline(iss, amountStr, ';') &&
                    std::getline(iss, dateStr, ';') &&
                    std::getline(iss, typeStr, ';') &&
                    std::getline(iss, categoryStr, ';') &&
                    std::getline(iss, accountType, ';'))
                {
                    if (accountType == oldAccountName) {
                        if (updateAll) {
                            line = transactionName + ";" + amountStr + ";" + dateStr + ";" + typeStr + ";" + categoryStr + ";" + newAccountName + ";";
                        }
                    }
                }
                lines.push_back(line);
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

    void Account_TableForm::SaveUpdatedAccountToFile(const std::string& accountName, const std::string& newBalance, const std::string& newTransactionCount, const std::string& newDescription)
    {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        std::vector<std::string> lines;

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string currentAccountName, balance, transactionCount, description;
                if (std::getline(iss, currentAccountName, ':') &&
                    std::getline(iss, balance, ':') &&
                    std::getline(iss, transactionCount, ':') &&
                    std::getline(iss, description, ','))
                {
                    if (currentAccountName == accountName) {
                        line = accountName + ":" + newBalance + ":" + newTransactionCount + ":" + newDescription + ",";
                    }
                }
                lines.push_back(line);
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

    void Account_TableForm::LoadAccountsToComboBox_del() {
        comboBox_del_ch_ac->Items->Clear();
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
                    comboBox_del_ch_ac->Items->Add(gcnew String(accountName.c_str()));
                }
            }
            file.close();
        }
    }
    void Account_TableForm::LoadTransactionsForAccount(const std::string& accountName) {
        dataGridViewTransactions->Columns->Clear();
        dataGridViewTransactions->Columns->Add("Name", "Название");
        dataGridViewTransactions->Columns->Add("Amount", "Сумма");
        dataGridViewTransactions->Columns->Add("Date", "Дата");
        dataGridViewTransactions->Columns->Add("Type", "Тип");
        dataGridViewTransactions->Columns->Add("Category", "Категория");
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
                                            double balance = std::stod(amountStr) / 100.0;
                                            System::String^ formattedBalance = String::Format("{0:F2}", balance);
                                            int rowIndex = dataGridViewTransactions->Rows->Add();
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(transactionName.c_str());
                                            dataGridViewTransactions->Rows[rowIndex]->Cells["Amount"]->Value = formattedBalance;
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
            MessageBox::Show("По вашему запросу ничего не найдено.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }
        file.close();
    }

    void Account_TableForm::DeleteAccountTransactions(const std::string& accountName, bool deleteTransactions) {
        if (deleteTransactions) {
            msclr::interop::marshal_context context;
            std::string filePath = context.marshal_as<std::string>(gcnew System::String("transactions.txt"));
            std::ifstream file(filePath);
            std::vector<std::string> lines;

            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    std::istringstream iss(line);
                    std::string transactionName, amountStr, dateStr, typeStr, categoryStr, accountType;
                    if (std::getline(iss, transactionName, ';') &&
                        std::getline(iss, amountStr, ';') &&
                        std::getline(iss, dateStr, ';') &&
                        std::getline(iss, typeStr, ';') &&
                        std::getline(iss, categoryStr, ';') &&
                        std::getline(iss, accountType, ';'))
                    {
                        if (accountType != accountName) {
                            lines.push_back(line);
                        }
                    }
                }
                file.close();
            }

            std::ofstream outFile(filePath, std::ios::trunc);
            if (outFile.is_open()) {
                for (const auto& line : lines) {
                    outFile << line << std::endl;
                }
                outFile.close();
            }
        }
    }
    void Account_TableForm::DeleteAccountFromFile(const std::string& accountName) {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        std::vector<std::string> lines;

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string currentAccountName, balance, transactionCount, description;
                if (std::getline(iss, currentAccountName, ':') &&
                    std::getline(iss, balance, ':') &&
                    std::getline(iss, transactionCount, ':') &&
                    std::getline(iss, description, ','))
                {
                    if (currentAccountName != accountName) {
                        lines.push_back(line);
                    }
                }
            }
            file.close();
        }
        std::ofstream outFile(filePath, std::ios::trunc);
        if (outFile.is_open()) {
            for (const auto& line : lines) {
                outFile << line << std::endl;
            }
            outFile.close();
        }
    }

    System::Void Account_TableForm::показатьТолькоДляОдногоСчётаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
            this->groupBox1->Text = "Поиск транзакций по счёту!";
            this->dataGridViewTransactions->Visible = true;
            this->buttonLoadTransactions->Visible = true;
            this->buttonLoadTransactions->Text = "Найти транзакции!";
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
    System::Void Account_TableForm::информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("В данном окне вы можете просматривать данные о счетах и транзакциях.\nВ верхней таблице отображается название счёта, баланс, количество транзакций и описание счёта.\nВ нижней таблице отображаются транзакции по выбранному счёту.\nЕсли у вас нет ни одного счёта, просмотр транзакций будет заблокирован. Как только вы создадите хотя бы один счёт, возможность просмотра станет доступна.\nДля просмотра транзакций выберите счёт из списка 'Выберите счёт:' и транзакции отобразятся в нижней таблице.\nВы можете 'Редактировать' или 'Удалить' выбранную транзакцию.", "Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }
    System::Void Account_TableForm::вернутьсяВМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
    System::Void Account_TableForm::конвертацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CurrencyConverterForm^ convert = gcnew CurrencyConverterForm();
        convert->ShowDialog();
        return System::Void();
    }
    System::Void Account_TableForm::аналитикаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AccountAnalyticsForm^ analyticsForm = gcnew AccountAnalyticsForm();
        analyticsForm->ShowDialog();
        return System::Void();
    }
    System::Void Account_TableForm::редактироватьСчётToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadAccountsToComboBox_del();
        if (flag_edit_ac) {
            groupBox2->Visible = false;
            groupBox2->Text = "Редактирование счёта!";
            comboBox_del_ch_ac->Visible = false;
            label_del_ch->Visible = false;
            label_del_ch->Text = "Выберите счёт для редактирования!";
            button_change_ac->Visible = false;
            button_del_ac->Visible = false;
            flag_edit_ac = 0;
        }
        else if (!flag_edit_ac) {
            groupBox2->Visible = true;
            groupBox2->Text = "Редактирование счёта!";
            comboBox_del_ch_ac->Visible = true;
            label_del_ch->Visible = true;
            label_del_ch->Text = "Выберите счёт для редактирования!";
            button_change_ac->Visible = true;
            button_del_ac->Visible = false;
            flag_edit_ac = 1;
        }
        return System::Void();
    }
    System::Void Account_TableForm::удалитьСчётToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadAccountsToComboBox_del();
        if (flag_del_ac) {
            groupBox2->Visible = false;
            groupBox2->Text = "Удаление счёта!";
            comboBox_del_ch_ac->Visible = false;
            label_del_ch->Visible = false;
            label_del_ch->Text = "Выберите счёт для удаления!";
            button_del_ac->Visible = false;
            button_change_ac->Visible = false;
            flag_del_ac = 0;
        }
        else if (!flag_del_ac) {
            groupBox2->Visible = true;
            button_change_ac->Visible = false;
            groupBox2->Text = "Удаление счёта!";
            comboBox_del_ch_ac->Visible = true;
            label_del_ch->Visible = true;
            label_del_ch->Text = "Выберите счёт для удаления!";
            button_del_ac->Visible = true;
            flag_del_ac = 1;
        }
        return System::Void();

    }

    System::Void Account_TableForm::button_del_ac_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (comboBox_del_ch_ac->SelectedItem != nullptr) {
            String^ selectedAccount = comboBox_del_ch_ac->SelectedItem->ToString();
            std::string stdAccountName = msclr::interop::marshal_as<std::string>(selectedAccount);
            if (MessageBox::Show("Вы уверены, что хотите удалить счёт " + selectedAccount + "?", "Удаление счёта", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                if (MessageBox::Show("Удалить транзакции связанные с этим счётом?", "Удаление транзакций", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                    DeleteAccountTransactions(stdAccountName, true);
                    DeleteAccountFromFile(stdAccountName);
                    LoadAccountsToDataGridView();
                    UpdateBalancesFromTransactions();
                    LoadAccountsToComboBox_del();
                    groupBox2->Visible = false;
                    MessageBox::Show("Счёт и соответствующие транзакции к счёту успешно удалены.", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);

                }
                else {
                    DeleteAccountTransactions(stdAccountName, false);
                    DeleteAccountFromFile(stdAccountName);
                    LoadAccountsToDataGridView();
                    UpdateBalancesFromTransactions();
                    LoadAccountsToComboBox_del();
                    groupBox2->Visible = false;
                    MessageBox::Show("Счёт успешно удалён.", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
        }
        else {
            MessageBox::Show("Пожалуйста, выберите счёт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    System::Void Account_TableForm::button_change_ac_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (comboBox_del_ch_ac->SelectedItem != nullptr) {
            String^ selectedAccount = comboBox_del_ch_ac->SelectedItem->ToString();
            std::string stdOldAccountName = msclr::interop::marshal_as<std::string>(selectedAccount);
            String^ balance;
            String^ transactionCount;
            String^ description;
            msclr::interop::marshal_context context;
            std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
            std::ifstream file(filePath);

            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    std::istringstream iss(line);
                    std::string currentAccountName, balanceFromFile, transactionCountFromFile, descriptionFromFile;
                    if (std::getline(iss, currentAccountName, ':') &&
                        std::getline(iss, balanceFromFile, ':') &&
                        std::getline(iss, transactionCountFromFile, ':') &&
                        std::getline(iss, descriptionFromFile, ','))
                    {
                        if (currentAccountName == stdOldAccountName) {
                            balance = gcnew String(balanceFromFile.c_str());
                            transactionCount = gcnew String(transactionCountFromFile.c_str());
                            description = gcnew String(descriptionFromFile.c_str());
                            break;
                        }
                    }
                }
                file.close();
            }

            AccountForm^ accountForm = gcnew AccountForm();
            accountForm->SetEditMode(true);
            accountForm->SetAccountData(selectedAccount, balance, transactionCount, description);
            accountForm->Text = "Редактировать счёт";
            accountForm->label_creat_account->Text = "Редактировать счёт";
            accountForm->ShowDialog();

            
            LoadAccountsToDataGridView();
            groupBox2->Visible = false;
        }
        if (comboBox_del_ch_ac->SelectedItem == nullptr)
        {
            MessageBox::Show("Пожалуйста, выберите счёт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
        return System::Void();
    }
}