#include "CategoryForm.h"
#include <msclr\marshal_cppstd.h>


namespace Courseproject {
    std::vector<Category> categories; // ������ ������ �� ������ ����� CategoryForm.cpp
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
    // �������� ������ �� ��������� �����
    String^ categoryName = textBoxCategoryName->Text;
    String^ categoryDescription = textBoxCategoryDescription->Text;

    if (String::IsNullOrEmpty(categoryName))
    {
        MessageBox::Show("�������� ��������� �� ������ ���� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // ������� ������ Category � ������� ������������
    Category newCategory(msclr::interop::marshal_as<std::string>(categoryName), msclr::interop::marshal_as<std::string>(categoryDescription));

    // ��������� � ������ ���������
    categories.push_back(newCategory);

    // ������� ��������� ����
    textBoxCategoryName->Text = "";
    textBoxCategoryDescription->Text = "";
    return System::Void();
}

System::Void Courseproject::CategoryForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    //TransactionForm^ transactionForm = gcnew TransactionForm(this); // �������� ������ �� CategoryForm
    //transactionForm->Show();
    this->Close();
    return System::Void();
}
