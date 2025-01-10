#include "SearchTransactionForm.h"
#include <fstream>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <Windows.h>

namespace Courseproject {
    SearchTransactionForm::SearchTransactionForm()
    {
        InitializeComponent();
        LoadCategoriesAndAccountsToComboBoxes();
    }
    void SearchTransactionForm::LoadCategoriesAndAccountsToComboBoxes()
    {
        comboBoxCategory->Items->Clear();
        comboBoxAccount->Items->Clear();

        msclr::interop::marshal_context context;
        std::string categoryFilePath = context.marshal_as<std::string>(gcnew System::String("categories.txt"));
        std::string accountFilePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));

        std::ifstream fileCategory(categoryFilePath);
        if (fileCategory.is_open())
        {
            std::string line;
            while (std::getline(fileCategory, line))
            {
                std::istringstream iss(line);
                std::string name, description;
                if (std::getline(iss, name, ';') && std::getline(iss, description, ';'))
                {
                    comboBoxCategory->Items->Add(gcnew System::String(name.c_str()));
                }
            }
            fileCategory.close();
        }

        std::ifstream fileAccount(accountFilePath);
        if (fileAccount.is_open())
        {
            std::string line;
            while (std::getline(fileAccount, line))
            {
                std::istringstream iss(line);
                std::string name;
                std::string balance;
                std::string count;
                if (std::getline(iss, name, ':') && std::getline(iss, balance, ':') && std::getline(iss, count, ',')) {

                    std::string accountName;
                    std::istringstream nameStream(name);

                    std::getline(nameStream, accountName, ':');
                    comboBoxAccount->Items->Add(gcnew System::String(name.c_str()));
                }
            }
            fileAccount.close();
        }
    }
    void SearchTransactionForm::SearchTransactions() {
        // Проверка, что хотя бы один из чекбоксов выбран
        if (!checkBoxName->Checked && !checkBoxAmount->Checked &&
            !checkBoxDate->Checked && !checkBoxType->Checked &&
            !checkBoxCategory->Checked && !checkBoxAccount->Checked)
        {
            MessageBox::Show("Необходимо выбрать хотя бы один критерий для поиска.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return; // Выход из метода, если ничего не выбрано
        }
        
        dataGridView_search->Rows->Clear();
        dataGridView_search->Columns->Clear();

        // Добавляем столбец для номера строки
        dataGridView_search->Columns->Add("RowNumber", "#");
        dataGridView_search->Columns[0]->Width = 40;
        std::vector<Category*> categories;
        // Добавляем столбцы для транзакций
        dataGridView_search->Columns->Add("TransactionName", "Название транзакции");
        dataGridView_search->Columns->Add("TransactionAmount", "Сумма");
        dataGridView_search->Columns->Add("TransactionDate", "Дата");
        dataGridView_search->Columns->Add("TransactionType", "Тип");
        dataGridView_search->Columns->Add("CategoryName", "Категория");
        dataGridView_search->Columns->Add("AccountName", "Счёт");

        categories.clear();//очищаем старые данные, если были
        msclr::interop::marshal_context context;
        std::string filePathCategory = context.marshal_as<std::string>(gcnew System::String("categories.txt"));
        std::ifstream fileCategory(filePathCategory);

        if (fileCategory.is_open())
        {
            std::string line;
            while (std::getline(fileCategory, line))
            {
                std::istringstream iss(line);
                std::string name, description;
                if (std::getline(iss, name, ';') && std::getline(iss, description, ';'))
                {
                    Category* newCategory = new Category(name, description);
                    categories.push_back(newCategory);
                }
            }
            fileCategory.close();
        }

        std::vector<Transaction> filteredTransactions;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("transactions.txt"));
        std::ifstream file(filePath);

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string transactionName, transactionAmountStr, transactionDate, transactionType, categoryName, accountName;
                if (std::getline(iss, transactionName, ';') &&
                    std::getline(iss, transactionAmountStr, ';') &&
                    std::getline(iss, transactionDate, ';') &&
                    std::getline(iss, transactionType, ';') &&
                    std::getline(iss, categoryName, ';') &&
                    std::getline(iss, accountName, ';'))
                {
                    int transactionAmount = std::stoi(transactionAmountStr);
                    Category* selectedCategory = nullptr;

                    for (Category* category : categories)
                    {
                        if (category->getName() == categoryName) {
                            selectedCategory = category;
                            break;
                        }
                    }
                    Transaction newTransaction(transactionName, transactionAmount, transactionDate, transactionType, selectedCategory, accountName);

                    bool match = true;
                    //Поиск по имени
                    if (checkBoxName->Checked) {
                        std::string nameSearch = msclr::interop::marshal_as<std::string>(textBoxName->Text);
                        if (newTransaction.getName() != nameSearch) {
                            match = false;
                        }
                    }
                    //Поиск по сумме
                    if (checkBoxAmount->Checked) {
                        int amountSearch = 0;
                        try
                        {
                            amountSearch = Int32::Parse(textBoxAmount->Text);
                        }
                        catch (System::FormatException^)
                        {
                            match = false;
                        }
                        if (match) {
                            if (radioButtonAmountEqual->Checked) {
                                if (newTransaction.getAmount() != amountSearch)
                                    match = false;
                            }
                            else if (radioButtonAmountLess->Checked)
                            {
                                if (newTransaction.getAmount() >= amountSearch)
                                    match = false;
                            }
                            else if (radioButtonAmountMore->Checked)
                            {
                                if (newTransaction.getAmount() <= amountSearch)
                                    match = false;
                            }
                        }
                    }
                    //Поиск по дате
                    if (checkBoxDate->Checked) {
                        System::DateTime dateSearch = dateTimePickerDate->Value;
                        System::String^ dateSearchStr = dateSearch.ToString("dd.MM.yyyy");
                        if (msclr::interop::marshal_as<std::string>(dateSearchStr) != newTransaction.getDate())
                        {
                            match = false;
                        }
                    }
                    //Поиск по типу
                    if (checkBoxType->Checked) {
                        if (comboBoxType->SelectedItem) {
                            System::String^ selectedType = comboBoxType->SelectedItem->ToString();
                            if (newTransaction.getType() != msclr::interop::marshal_as<std::string>(selectedType))
                            {
                                match = false;
                            }
                        }
                    }
                    //Поиск по категории
                    if (checkBoxCategory->Checked)
                    {
                        if (comboBoxCategory->SelectedItem)
                        {
                            System::String^ selectedCategoryName = comboBoxCategory->SelectedItem->ToString();
                            if (newTransaction.getCategory() != nullptr && newTransaction.getCategory()->getName() != msclr::interop::marshal_as<std::string>(selectedCategoryName))
                            {
                                match = false;
                            }
                        }
                    }
                    //Поиск по счёту
                    if (checkBoxAccount->Checked)
                    {
                        if (comboBoxAccount->SelectedItem) {
                            System::String^ selectedAccountName = comboBoxAccount->SelectedItem->ToString();
                            if (newTransaction.getTypeAccount() != msclr::interop::marshal_as<std::string>(selectedAccountName)) {
                                match = false;
                            }
                        }
                    }
                    if (match) {
                        filteredTransactions.push_back(newTransaction);
                    }
                }
            }
            file.close();
        }
        if (filteredTransactions.empty())
        {
            MessageBox::Show("По вашему запросу ничего не найдено.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }
        int rowNumber = 1;
        for (const auto& transaction : filteredTransactions) {
            int rowIndex = dataGridView_search->Rows->Add();
            dataGridView_search->Rows[rowIndex]->Cells["RowNumber"]->Value = rowNumber;
            dataGridView_search->Rows[rowIndex]->Cells["TransactionName"]->Value = gcnew System::String(transaction.getName().c_str());
            dataGridView_search->Rows[rowIndex]->Cells["TransactionAmount"]->Value = transaction.getAmount();
            dataGridView_search->Rows[rowIndex]->Cells["TransactionDate"]->Value = gcnew System::String(transaction.getDate().c_str());
            dataGridView_search->Rows[rowIndex]->Cells["TransactionType"]->Value = gcnew System::String(transaction.getType().c_str());
            if (transaction.getCategory() != nullptr) { // Проверка, что категория не nullptr
                dataGridView_search->Rows[rowIndex]->Cells["CategoryName"]->Value = gcnew System::String(transaction.getCategory()->getName().c_str());
            }
            dataGridView_search->Rows[rowIndex]->Cells["AccountName"]->Value = gcnew System::String(transaction.getTypeAccount().c_str());
            rowNumber++;
        }
    }


    System::Void SearchTransactionForm::button_Search_Click(System::Object^ sender, System::EventArgs^ e)
    {
        SearchTransactions();
        return System::Void();
    }

    System::Void SearchTransactionForm::buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
    {
        checkBoxName->Checked = false;
        textBoxName->Text = "";

        checkBoxAmount->Checked = false;
        textBoxAmount->Text = "";
        radioButtonAmountEqual->Checked = false;
        radioButtonAmountLess->Checked = false;
        radioButtonAmountMore->Checked = false;

        checkBoxDate->Checked = false;
        dateTimePickerDate->Value = System::DateTime::Now;

        checkBoxType->Checked = false;
        comboBoxType->SelectedIndex = -1;

        checkBoxCategory->Checked = false;
        comboBoxCategory->SelectedIndex = -1;

        checkBoxAccount->Checked = false;
        comboBoxAccount->SelectedIndex = -1;
        dataGridView_search->Rows->Clear();
        return System::Void();
    }
    System::Void SearchTransactionForm::информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Будет текст", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
        
    }
    System::Void SearchTransactionForm::вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
}
