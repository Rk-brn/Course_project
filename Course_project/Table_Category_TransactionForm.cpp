#include "Table_Category_TransactionForm.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <Windows.h>

namespace Courseproject {
    Table_Category_TransactionForm::Table_Category_TransactionForm()
    {
        InitializeComponent();
        LoadCategoriesToDataGridView(); // �������� ��������� ��� �������� �����
        LoadTransactionsToDataGridView();
        TransactionForm^ transactionForm = gcnew TransactionForm();
        transactionForm->LoadTransactionFile(); // ��������� ������ ���������� �� �����
        transactionForm->Close();
    }

    System::Void Table_Category_TransactionForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CategoryForm^ categoryForm = gcnew CategoryForm();
        categoryForm->ShowDialog();
        
    }

    System::Void Table_Category_TransactionForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadCategoriesToDataGridView();
    }

    void Table_Category_TransactionForm::LoadCategoriesToDataGridView() {
        CategoryForm categoryForm;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(categoryForm.categoryFilePath);
        std::ifstream file(filePath);

        // ������� ���������� ������� (���� ����)
        dataGridView1->Columns->Clear();
        // ��������� �������
        dataGridView1->Columns->Add("Name", "��������");
        dataGridView1->Columns->Add("Description", "��������");

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
    void Table_Category_TransactionForm::LoadTransactionsToDataGridView() {
        // ������� ������� ����������
        dataGridViewTransactions->Rows->Clear();
        dataGridViewTransactions->Columns->Clear();

        // ��������� ������� ��� ������ ������
        dataGridViewTransactions->Columns->Add("RowNumber", "#");
        dataGridViewTransactions->Columns[0]->Width = 40;

        // ��������� ������� ��� ����������
        dataGridViewTransactions->Columns->Add("TransactionName", "�������� ����������");
        dataGridViewTransactions->Columns->Add("TransactionAmount", "�����");
        dataGridViewTransactions->Columns->Add("TransactionDate", "����");
        dataGridViewTransactions->Columns->Add("TransactionType", "���");
        dataGridViewTransactions->Columns->Add("CategoryName", "���������");
        dataGridViewTransactions->Columns->Add("AccountName", "����");

        msclr::interop::marshal_context context2;
        std::string filePath = context2.marshal_as<std::string>(gcnew System::String("transactions.txt"));
        std::ifstream file(filePath);

        if (file.is_open()) {
            std::string line;
            int rowNumber = 1;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string transactionName, transactionAmountStr, transactionDate, transactionType, categoryName, accountName;

                if (std::getline(iss, transactionName, ';') &&
                    std::getline(iss, transactionAmountStr, ';') &&
                    std::getline(iss, transactionDate, ';') &&
                    std::getline(iss, transactionType, ';') &&
                    std::getline(iss, categoryName, ';') &&
                    std::getline(iss, accountName, ';'))
                {

                    int rowIndex = dataGridViewTransactions->Rows->Add();
                    dataGridViewTransactions->Rows[rowIndex]->Cells["RowNumber"]->Value = rowNumber;
                    dataGridViewTransactions->Rows[rowIndex]->Cells["TransactionName"]->Value = gcnew System::String(transactionName.c_str());
                    dataGridViewTransactions->Rows[rowIndex]->Cells["TransactionAmount"]->Value = gcnew System::String(transactionAmountStr.c_str());
                    dataGridViewTransactions->Rows[rowIndex]->Cells["TransactionDate"]->Value = gcnew System::String(transactionDate.c_str());
                    dataGridViewTransactions->Rows[rowIndex]->Cells["TransactionType"]->Value = gcnew System::String(transactionType.c_str());
                    dataGridViewTransactions->Rows[rowIndex]->Cells["CategoryName"]->Value = gcnew System::String(categoryName.c_str());
                    dataGridViewTransactions->Rows[rowIndex]->Cells["AccountName"]->Value = gcnew System::String(accountName.c_str());


                    rowNumber++;
                }
            }
            file.close();
        }
    }
    System::Void Table_Category_TransactionForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (flag_prosmotr) {
            this->groupBox_prosmotr_category->Visible=false;
            this->dataGridView1->Visible = false;
            this->button1->Visible = false;
            this->button2->Visible = false;
            flag_prosmotr = 0;
        }
        else if (!flag_prosmotr) {
            this->groupBox_prosmotr_category->Visible = true;
            this->dataGridView1->Visible = true;
            this->button1->Visible = true;
            this->button2->Visible = true;
            flag_prosmotr = 1;
        }
        return System::Void();
    }
    System::Void Table_Category_TransactionForm::������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        TransactionForm^ transaction_form = gcnew TransactionForm();
        transaction_form->ShowDialog();
        return System::Void();
    }
    System::Void Table_Category_TransactionForm::���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        LoadTransactionsToDataGridView();
        return System::Void();
    }
    System::Void Table_Category_TransactionForm::�������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (flag_edit_del) {
            this->groupBox_edit_del_tran->Visible = false;
            this->textBox_edit_del_tr->Visible = false;
            this->button_edit_del_tr->Visible = false;
            flag_edit_del = 0;
       }
        else if (!flag_edit_del) {
            this->groupBox_edit_del_tran->Text = "�������� ������";
            this->groupBox_edit_del_tran->Visible = true;
            this->textBox_edit_del_tr->Visible = true;
            this->textBox_edit_del_tr->Text = "";
            this->button_edit_del_tr->Visible = true;
            this->button_edit_del_tr->Text = "������� ������";
            flag_edit_del = 1;
        }
        return System::Void();
    }
    System::Void Table_Category_TransactionForm::button_edit_del_tr_Click(System::Object^ sender, System::EventArgs^ e) {
        // �������� ����� ������ �� ����������
        String^ rowNumberStr = textBox_edit_del_tr->Text;
        if (String::IsNullOrEmpty(rowNumberStr)) {
            MessageBox::Show("����������, ������� ����� ������ ��� ��������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        int rowNumber;
        try {
            rowNumber = System::Int32::Parse(rowNumberStr);
        }
        catch (System::FormatException^) {
            MessageBox::Show("�������� ������ ������ ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (rowNumber <= 0 || rowNumber > dataGridViewTransactions->Rows->Count) {
            MessageBox::Show("�������� ����� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("transactions.txt"));
        std::ifstream file(filePath);
        std::vector<std::string> lines;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line))
            {
                lines.push_back(line);
            }
            file.close();
        }

        if (rowNumber > 0 && rowNumber <= static_cast<int>(lines.size())) {
            lines.erase(lines.begin() + rowNumber - 1);
            std::ofstream outFile(filePath);
            if (outFile.is_open())
            {
                for (const auto& line : lines) {
                    outFile << line << std::endl;
                }
                outFile.close();
            }
            // ���������� ������� transactions
            TransactionForm^ transactionForm = gcnew TransactionForm();
            transactionForm->LoadTransactionFile(); // ��������� ������ ���������� �� �����
            transactionForm->Close();

            MessageBox::Show("������ ������� �������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadTransactionsToDataGridView();
        }
        else {
            MessageBox::Show("�������� ����� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        return System::Void();
    }
 }