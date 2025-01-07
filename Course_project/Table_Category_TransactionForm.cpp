#include "Table_Category_TransactionForm.h"
#include "CategoryForm.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <sstream>

namespace Courseproject {
    Table_Category_TransactionForm::Table_Category_TransactionForm()
    {
        InitializeComponent();
    }

    System::Void Table_Category_TransactionForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CategoryForm^ categoryForm = gcnew CategoryForm();
        categoryForm->ShowDialog();
        
    }

    System::Void Table_Category_TransactionForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CategoryForm categoryForm;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(categoryForm.categoryFilePath);
        std::ifstream file(filePath);

        // Очищаем предыдущие столбцы (если есть)
        dataGridView1->Columns->Clear();
        // Добавляем столбцы
        dataGridView1->Columns->Add("Name", "Название");
        dataGridView1->Columns->Add("Description", "Описание");

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, description;
                if (std::getline(iss, name, ';') && std::getline(iss, description, ';'))
                {
                    int rowIndex = dataGridView1->Rows->Add();
                    dataGridView1->Rows[rowIndex]->Cells["Name"]->Value = gcnew System::String(name.c_str());
                    dataGridView1->Rows[rowIndex]->Cells["Description"]->Value = gcnew System::String(description.c_str());
                }
            }
            file.close();
        }
    }
 }