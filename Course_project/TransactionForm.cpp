#include "TransactionForm.h"
#include <msclr\marshal_cppstd.h>
#include <ctime>
#include <sstream> // ��������� ������������ ���� ��� istringstream
#include <fstream>
#include "CategoryForm.h"
#include <regex>  // ��� ������������� ���������� ���������
#include <algorithm> // ��� std::remove

namespace Courseproject {
    std::vector<Transaction> transactions;
    const char* TRANSACTION_FILE_NAME = "transactions.txt";
    const char* CATEGOR_FILE_NAME = "categories.txt";
    const char* ACCOUNT_FILE_NAME = "account.txt";
    TransactionForm::TransactionForm() : transactionFilePath(gcnew System::String(TRANSACTION_FILE_NAME)), categoryFilePath(gcnew System::String(CATEGOR_FILE_NAME)), accountFilePath(gcnew System::String(ACCOUNT_FILE_NAME))
    {
        InitializeComponent();
        LoadCategoriesFromFile();// �������� ��������� �� �����
        LoadAccountsFromFile();
    }

    bool TransactionForm::isValidTransactionAmount(const std::string& str)
    {
        std::regex pattern("^\\d+\\.\\d{2}$");
        return std::regex_match(str, pattern);
    }

    void  TransactionForm::LoadAccountsFromFile()
    {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(accountFilePath);
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
                if (std::getline(iss, name, ':') && std::getline(iss, balance, ':') && std::getline(iss, count, ',')) {

                    std::string accountName;
                    std::istringstream nameStream(name);

                    std::getline(nameStream, accountName, ':');

                    comboBox_Account->Items->Add(gcnew String(accountName.c_str()));
                }
            }
            file.close();
        }
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

    // ����� ��� �������� ���������� �� �����
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
                std::string name, amountStr, date, type, categoryName, accountType;
                if (std::getline(iss, name, ';') && std::getline(iss, amountStr, ';') && std::getline(iss, date, ';') && std::getline(iss, type, ';') && std::getline(iss, categoryName, ';') && std::getline(iss, accountType, ';'))
                {
                    int amount = std::stod(amountStr);

                    // ����� ���������
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
                        transactions.push_back(Transaction(name, amount, date, type, category, accountType));
                    else
                    {
                        MessageBox::Show("������ �������� �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
                    << transaction.getCategory()->getName() << ";"
                    << transaction.getTypeAccount() << ";\n";
            }
            file.close();
        }
    }

    System::Void TransactionForm::button_TransactionCreat_Click(System::Object^ sender, System::EventArgs^ e) {
        // ��������� ������ �� ����� �����
        String^ transactionName = textBox_TransactionText->Text;
        String^ transactionAmountStr = textBox_TransactionAmount->Text;
        String^ transactionType = comboBox_TransactionType->SelectedItem != nullptr ? comboBox_TransactionType->SelectedItem->ToString() : "";
        String^ selectedCategoryName = comboBox_Category->SelectedItem != nullptr ? comboBox_Category->SelectedItem->ToString() : "";
        System::DateTime selectedDate = dateTimePicker_Date->Value;
        String^ dateString = selectedDate.ToString("dd/MM/yyyy");
        String^ selectedAccountName = comboBox_Account->SelectedItem != nullptr ? comboBox_Account->SelectedItem->ToString() : "";

        if (String::IsNullOrEmpty(transactionName) || String::IsNullOrEmpty(transactionAmountStr)
            || String::IsNullOrEmpty(transactionType) || String::IsNullOrEmpty(selectedCategoryName) || String::IsNullOrEmpty(dateString)) {
            MessageBox::Show("����������, ��������� ��� ����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        std::string transactionAmountStrStd = msclr::interop::marshal_as<std::string>(transactionAmountStr);
        if (!isValidTransactionAmount(transactionAmountStrStd))
        {
            MessageBox::Show("������������ ���� �����. ������� ����� � ������� �����.����� (��������, 123.45)", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }


        double amount = std::stod(transactionAmountStrStd) * 100.0;
        int transactionAmount = static_cast<int>(std::round(amount));


        Category* selectedCategory = nullptr;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(categoryFilePath);
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            bool found = false;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, description;
                if (std::getline(iss, name, ';') && std::getline(iss, description, ';'))
                {
                    if (gcnew String(name.c_str()) == selectedCategoryName)
                    {
                        selectedCategory = new Category(name, description);
                        found = true;
                        break;
                    }
                }

            }
            file.close();
            if (!found) {
                MessageBox::Show("��������� ��������� �� ������� � �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

        }
        else {
            MessageBox::Show("������ �������� ����� ���������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }



        if (selectedCategory == nullptr) {
            MessageBox::Show("��������� ��������� �� �������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Transaction newTransaction(msclr::interop::marshal_as<std::string>(transactionName),
            transactionAmount,
            msclr::interop::marshal_as<std::string>(dateString),
            msclr::interop::marshal_as<std::string>(transactionType),
            selectedCategory,
            msclr::interop::marshal_as<std::string>(selectedAccountName)
        );
        msclr::interop::marshal_context context2;
        std::string transactionFilePath = context2.marshal_as<std::string>(this->transactionFilePath);

        if (isEditing) {
            std::ifstream file(transactionFilePath);
            std::vector<std::string> lines;

            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line))
                {
                    lines.push_back(line);
                }
                file.close();
            }

            if (rowIndexToEdit >= 0 && rowIndexToEdit < lines.size()) {
                std::string newTransactionLine = msclr::interop::marshal_as<std::string>(transactionName) + ";" +
                    std::to_string(transactionAmount) + ";" +
                    msclr::interop::marshal_as<std::string>(dateString) + ";" +
                    msclr::interop::marshal_as<std::string>(transactionType) + ";" +
                    msclr::interop::marshal_as<std::string>(selectedCategoryName) + ";" +
                    msclr::interop::marshal_as<std::string>(selectedAccountName) + ";";


                lines[rowIndexToEdit] = newTransactionLine;
                std::ofstream outFile(transactionFilePath);
                if (outFile.is_open()) {
                    for (const auto& line : lines) {
                        outFile << line << std::endl;
                    }
                    outFile.close();

                    MessageBox::Show("���������� ������� ��������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    isChanged = true;
                    this->Close();

                }
                else {
                    MessageBox::Show("������ �������� ����� ��� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }

            }
            else {
                MessageBox::Show("������ ��� �������������� ����������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }

        }
        else {
            transactions.push_back(newTransaction);
            SaveTransactionsToFile();
            MessageBox::Show("���������� ������� �������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        // ������� �����
        textBox_TransactionText->Text = "";
        textBox_TransactionAmount->Text = "";
        comboBox_TransactionType->SelectedIndex = -1;
        comboBox_Category->SelectedIndex = -1;
        dateTimePicker_Date->Value = System::DateTime::Now;
        comboBox_Account->SelectedIndex = -1;
        return System::Void();
    }

    System::Void TransactionForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("� ������ ���� �� ������ ��������� ��� ������������� ����������.\n��� �������� ����� ���������� ��������� ��� ���� � ������� ������ '������� ����������'.\n��� �������������� ���������� �������� ������ ����������, ������� ��������� � ���� � ������� ������ '������� ����������'.\n���� �� ������ ���� �������. ����� ������� �� ������ '������� ����������', �� ������ ���������� �� �������� �������� ��� �������������� ����������.\n�������� ���� ����������, ��������, ���������, �����, ��� � ����.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }

    System::Void TransactionForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
}
