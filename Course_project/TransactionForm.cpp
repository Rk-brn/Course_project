#include "TransactionForm.h"
#include <msclr\marshal_cppstd.h>
#include <ctime>
#include <sstream> // ��������� ������������ ���� ��� istringstream


namespace Courseproject {

    TransactionForm::TransactionForm(Courseproject::CategoryForm^ categoryForm) : categoryForm(categoryForm)
    {
        InitializeComponent();
        // ���������� comboBox_Category ���������� �� categoryForm.categories
        for (Category& category : categoryForm->GetCategories())
        {
            comboBox_Category->Items->Add(gcnew String(category.getName().c_str()));
        }
    }
    System::Void TransactionForm::button_TransactionCreat_Click(System::Object^ sender, System::EventArgs^ e) {
        // ��������� ������ �� ����� �����
        String^ transactionName = textBox_TransactionText->Text;
        String^ transactionAmountStr = textBox_TransactionAmount->Text;
        String^ transactionType = comboBox_TransactionType->SelectedItem != nullptr ? comboBox_TransactionType->SelectedItem->ToString() : "";
        String^ selectedCategoryName = comboBox_Category->SelectedItem != nullptr ? comboBox_Category->SelectedItem->ToString() : "";
        String^ dateString = maskedTextBox_DataType->Text;


        if (String::IsNullOrEmpty(transactionName) || String::IsNullOrEmpty(transactionAmountStr) ||
            String::IsNullOrEmpty(transactionType) || String::IsNullOrEmpty(selectedCategoryName) || String::IsNullOrEmpty(dateString)) {
            MessageBox::Show("����������, ��������� ��� ����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }


        double transactionAmount;
        try {
            transactionAmount = System::Double::Parse(transactionAmountStr);
        }
        catch (System::FormatException^) {
            MessageBox::Show("�������� ������ �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }


        Category* selectedCategory = nullptr;
        for (Category& category : categoryForm->GetCategories())
        {
            if (gcnew String(category.getName().c_str()) == selectedCategoryName) {
                selectedCategory = &category;
                break;
            }
        }
        if (selectedCategory == nullptr) {
            MessageBox::Show("��������� ��������� �� �������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

       


        // ������� ������ ����������
        Transaction newTransaction(msclr::interop::marshal_as<std::string>(transactionName),
            transactionAmount,
            msclr::interop::marshal_as<std::string>(dateString),
            msclr::interop::marshal_as<std::string>(transactionType),
            selectedCategory
        );

        transactions.push_back(newTransaction);


        MessageBox::Show("���������� ������� �������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
        // ������� �����
        textBox_TransactionText->Text = "";
        textBox_TransactionAmount->Text = "";
        comboBox_TransactionType->SelectedIndex = -1;
        comboBox_Category->SelectedIndex = -1;
        maskedTextBox_DataType->Text = "";

        return System::Void();
    }
}