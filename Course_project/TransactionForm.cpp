#include "TransactionForm.h"
#include <msclr\marshal_cppstd.h>
#include <ctime>
#include <sstream> // Добавляем заголовочный файл для istringstream
#include <fstream>
#include "CategoryForm.h"

namespace Courseproject {
    std::vector<Transaction> transactions;
    const char* TRANSACTION_FILE_NAME = "transactions.txt";
    const char* CATEGOR_FILE_NAME = "categories.txt";

    TransactionForm::TransactionForm() : transactionFilePath(gcnew System::String(TRANSACTION_FILE_NAME)), categoryFilePath(gcnew System::String(CATEGOR_FILE_NAME))
    {
        InitializeComponent();
        LoadCategoriesFromFile();// Загрузка категорий из файла
    }


    void  TransactionForm::LoadCategoriesFromFile()
    {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(categoryFilePath);
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, description;
                if (std::getline(iss, name, ';') && std::getline(iss, description, ';'))
                {
                    comboBox_Category->Items->Add(gcnew String(name.c_str()));
                }
            }
            file.close();
        }
    }

    // Метод для загрузки транзакций из файла
    std::vector<Transaction> TransactionForm::LoadTransactionFile()
    {
        
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(transactionFilePath);
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, amountStr, date, type, categoryName;
                if (std::getline(iss, name, ';') && std::getline(iss, amountStr, ';') && std::getline(iss, date, ';') && std::getline(iss, type, ';') && std::getline(iss, categoryName, ';'))
                {
                    double amount = std::stod(amountStr);

                    // Поиск категории
                    Category* category = nullptr;
                    std::ifstream categoryFile(context.marshal_as<std::string>(categoryFilePath));
                    if (categoryFile.is_open()) {
                        std::string categoryLine;
                        while (std::getline(categoryFile, categoryLine)) {
                            std::istringstream categoryIss(categoryLine);
                            std::string catName, catDescription;
                            if (std::getline(categoryIss, catName, ';') && std::getline(categoryIss, catDescription, ';'))
                            {
                                if (catName == categoryName)
                                {
                                    category = new Category(catName, catDescription);
                                    break;
                                }
                            }
                        }
                        categoryFile.close();
                    }
                    if (category != nullptr)
                        transactions.push_back(Transaction(name, amount, date, type, category));
                    else
                    {
                        MessageBox::Show("Ошибка загрузки файла.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
            }
            file.close();
        }
        return transactions;
    }

    void  TransactionForm::SaveTransactionsToFile() {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(transactionFilePath);
        std::ofstream file(filePath);
        if (file.is_open())
        {
            for (const auto& transaction : transactions)
            {
                file << transaction.getName() << ";"
                    << transaction.getAmount() << ";"
                    << transaction.getDate() << ";"
                    << transaction.getType() << ";"
                    << transaction.getCategory()->getName() << ";\n";
            }
            file.close();
        }
    }

    System::Void TransactionForm::button_TransactionCreat_Click(System::Object^ sender, System::EventArgs^ e) {
        // Получение данных из полей формы
        String^ transactionName = textBox_TransactionText->Text;
        String^ transactionAmountStr = textBox_TransactionAmount->Text; String^ transactionType = comboBox_TransactionType->SelectedItem != nullptr ? comboBox_TransactionType->SelectedItem->ToString() : "";
        String^ selectedCategoryName = comboBox_Category->SelectedItem != nullptr ? comboBox_Category->SelectedItem->ToString() : "";
        String^ dateString = maskedTextBox_DataType->Text;


        if (String::IsNullOrEmpty(transactionName) || String::IsNullOrEmpty(transactionAmountStr)
            || String::IsNullOrEmpty(transactionType) || String::IsNullOrEmpty(selectedCategoryName) || String::IsNullOrEmpty(dateString)) {
            MessageBox::Show("Пожалуйста, заполните все поля.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }


        double transactionAmount;
        try {
            transactionAmount = System::Double::Parse(transactionAmountStr);
        }
        catch (System::FormatException^) {
            MessageBox::Show("Неверный формат суммы.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }


        Category* selectedCategory = nullptr;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(categoryFilePath);
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, description;
                if (std::getline(iss, name, ';') && std::getline(iss, description, ';'))
                {
                    if (gcnew String(name.c_str()) == selectedCategoryName)
                    {
                        selectedCategory = new Category(name, description);
                        break;
                    }
                }
            }
            file.close();
        }

        if (selectedCategory == nullptr) {
            MessageBox::Show("Выбранная категория не найдена.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Создаем объект транзакции
        Transaction newTransaction(msclr::interop::marshal_as<std::string>(transactionName),
            transactionAmount,
            msclr::interop::marshal_as<std::string>(dateString),
            msclr::interop::marshal_as<std::string>(transactionType),
            selectedCategory
        );

        transactions.push_back(newTransaction);
        SaveTransactionsToFile();

        MessageBox::Show("Транзакция успешно создана.", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
        // Очистка полей
        textBox_TransactionText->Text = "";
        textBox_TransactionAmount->Text = "";
        comboBox_TransactionType->SelectedIndex = -1;
        comboBox_Category->SelectedIndex = -1;
        maskedTextBox_DataType->Text = "";

        return System::Void();
    }

    System::Void TransactionForm::информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Будет текст", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }

    System::Void TransactionForm::вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
}
