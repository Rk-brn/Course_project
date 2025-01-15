#include "AccountForm.h"

#include <ctime>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <iostream>


std::vector<Account> accounts;

void Courseproject::AccountForm::SetEditMode(bool editMode)
{
    this->editMode = editMode;
    if (editMode) {
        button_creat_account->Text = "Сохранить изменения";
    }
    else {
        button_creat_account->Text = "Создать счёт";
    }
}

void Courseproject::AccountForm::SetAccountData(String^ name, String^ balance, String^ transactionCount, String^ description)
{
    textBox_name_account->Text = name;
    textBox_balance_account->Text = description;
    
    originalAccountName = name;
}

System::Void Courseproject::AccountForm::button_creat_account_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ nameStr = textBox_name_account->Text;
    String^ descriptionStr = textBox_balance_account->Text;

    if (nameStr->Trim()->Length == 0) {
        MessageBox::Show("Поле 'Имя счёта' не может быть пустым!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    std::string name = msclr::interop::marshal_as<std::string>(nameStr);
    std::string description = msclr::interop::marshal_as<std::string>(descriptionStr);
    int balance = 0;
    int countTrans = 0;

    std::ofstream file;
    if (editMode) { // Режим редактирования
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream inputFile(filePath);

        if (!inputFile.is_open()) {
            MessageBox::Show("Не удалось открыть файл для чтения!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        std::vector<std::string> newLines;
        std::string oldAccountName = context.marshal_as<std::string>(originalAccountName);
        std::string line;

        while (std::getline(inputFile, line)) {
            size_t pos = line.find(':');
            if (pos != std::string::npos) {
                std::string currentAccountName = line.substr(0, pos);
                if (currentAccountName == oldAccountName) {
                    line = name + ":" + std::to_string(balance) + ":" + std::to_string(countTrans) + ":" + description + ",";
                }
            }
            newLines.push_back(line);
        }
        inputFile.close();

        file.open("account.txt", std::ios::trunc);
        if (!file.is_open()) {
            MessageBox::Show("Не удалось открыть файл для перезаписи!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        for (const auto& line : newLines) {
            std::cout << "Строка для записи (редактирование): " << line << std::endl; //отладка
            file << line.c_str() << std::endl;
        }
        file.close();

    }
    else { // Режим создания
        file.open("account.txt", std::ios::app);
        if (!file.is_open()) {
            MessageBox::Show("Не удалось открыть файл для записи!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        std::string output_line = name + ":" + std::to_string(balance) + ":" + std::to_string(countTrans) + ":" + description + ",";
        std::cout << "Строка для записи (создание): " << output_line + "\n" << std::endl; // отладка
        file << output_line << std::endl;
        file.close();
        MessageBox::Show("Счёт успешно создан!", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    textBox_balance_account->Text = "";
    textBox_name_account->Text = "";
    this->Close();
    return System::Void();
}


System::Void Courseproject::AccountForm::информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Будет текст", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
    return System::Void();
    
}

System::Void Courseproject::AccountForm::вернутьсяНазадКСчетамToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    return System::Void();
}
