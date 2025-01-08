#include "CategoryForm.h"
#include <fstream>
#include <sstream>
#include <msclr\marshal.h>
#include <msclr/marshal_cppstd.h>
namespace Courseproject {
    const char* CATEGORY_FILE_NAME = "categories.txt";
}

Courseproject::CategoryForm::CategoryForm(void) : categoryFilePath(gcnew System::String(CATEGORY_FILE_NAME))
{
    InitializeComponent();
    
}

std::vector<Category> Courseproject::CategoryForm::LoadCategoriesFromFile()
{
    std::vector<Category> categories;
    msclr::interop::marshal_context context;
    // Маршалинг System::String^ в std::string
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
                categories.push_back(Category(name, description));
            }
        }
        file.close();
    }
    return categories;
}

void Courseproject::CategoryForm::SaveCategoriesToFile()
{
    msclr::interop::marshal_context context;
    // Маршалинг System::String^ в std::string
    std::string filePath = context.marshal_as<std::string>(categoryFilePath);
    std::ofstream file(filePath);
    if (file.is_open())
    {
        for (const auto& category : LoadCategoriesFromFile()) // Используем функцию для загрузки категорий из файла
        {
            file << category.getName() << ";" << category.getDescription() << ";\n";
        }
        file.close();
    }
}


System::Void Courseproject::CategoryForm::buttonCreateCategory_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ categoryName = textBoxCategoryName->Text;
    String^ categoryDescription = textBoxCategoryDescription->Text;

    if (String::IsNullOrEmpty(categoryName))
    {
        MessageBox::Show("Название категории не должно быть пустым.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    Category newCategory(msclr::interop::marshal_as<std::string>(categoryName), msclr::interop::marshal_as<std::string>(categoryDescription));

    std::vector<Category> categories = LoadCategoriesFromFile();
    categories.push_back(newCategory);

    msclr::interop::marshal_context context;
    std::string filePath = context.marshal_as<std::string>(categoryFilePath);
    std::ofstream file(filePath);
    if (file.is_open())
    {
        for (const auto& category : categories)
        {
            file << category.getName() << ";" << category.getDescription() << ";\n";
        }
        file.close();
    }

    textBoxCategoryName->Text = "";
    textBoxCategoryDescription->Text = "";
    return System::Void();
}


System::Void Courseproject::CategoryForm::вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    //TransactionForm^ transactionForm = gcnew TransactionForm(this); // Передаем ссылку на CategoryForm
    //transactionForm->Show();
    this->Close();
    return System::Void();
}

System::Void Courseproject::CategoryForm::информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Будет текст", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
    return System::Void();
}

