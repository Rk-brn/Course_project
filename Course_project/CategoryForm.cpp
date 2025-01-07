#include "CategoryForm.h"
#include <msclr\marshal_cppstd.h>


namespace Courseproject {
    std::vector<Category> categories; // Создаём вектор на уровне файла CategoryForm.cpp
    std::vector<Category> CategoryForm::GetCategories() {
        return categories;
    }
}

Courseproject::CategoryForm::CategoryForm(void)
{
    InitializeComponent();
}

System::Void Courseproject::CategoryForm::buttonCreateCategory_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Получаем данные из текстовых полей
    String^ categoryName = textBoxCategoryName->Text;
    String^ categoryDescription = textBoxCategoryDescription->Text;

    if (String::IsNullOrEmpty(categoryName))
    {
        MessageBox::Show("Название категории не должно быть пустым.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Создаем объект Category с помощью конструктора
    Category newCategory(msclr::interop::marshal_as<std::string>(categoryName), msclr::interop::marshal_as<std::string>(categoryDescription));

    // Добавляем в вектор категорий
    categories.push_back(newCategory);

    // Очищаем текстовые поля
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
