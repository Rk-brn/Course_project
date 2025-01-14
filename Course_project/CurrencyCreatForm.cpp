
#include "CurrencyCreatForm.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr/marshal_cppstd.h>  // ���������� ���� � �����
#include <algorithm>

namespace Courseproject {
    const char* CURRENCY_FILE_NAME = "currencies.txt";

    // ������� ��� ��������, �������� �� ������ ������ (������ ����������� ������)
    bool isNumber(const std::string& str)
    {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }

    CurrencyCreatForm::CurrencyCreatForm(void) : currencyFilePath(gcnew System::String(CURRENCY_FILE_NAME))
    {
        InitializeComponent();
        LoadCurrenciesToDataGridView();
        LoadCurrenciesToComboBoxes();
    }

    void CurrencyCreatForm::LoadCurrenciesToDataGridView()
    {
        dataGridViewCurrencies->Rows->Clear();
        dataGridViewCurrencies->Columns->Clear();

        dataGridViewCurrencies->Columns->Add("CurrencyName", "�������� ������");
        dataGridViewCurrencies->Columns->Add("CurrencyRate", "���� ������");

        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(currencyFilePath);
        std::ifstream file(filePath);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                size_t separatorPos = line.find(':');
                if (separatorPos != std::string::npos) {
                    std::string name = line.substr(0, separatorPos);
                    std::string rate = line.substr(separatorPos + 1);
                    dataGridViewCurrencies->Rows->Add(gcnew System::String(name.c_str()), gcnew System::String(rate.c_str()));
                }
            }
            file.close();
        }
    }

    void CurrencyCreatForm::LoadCurrenciesToComboBoxes()
    {
        comboBoxCurrencies->Items->Clear();

        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(currencyFilePath);
        std::ifstream file(filePath);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                size_t separatorPos = line.find(':');
                if (separatorPos != std::string::npos) {
                    std::string name = line.substr(0, separatorPos);
                    comboBoxCurrencies->Items->Add(gcnew System::String(name.c_str()));
                }
            }
            file.close();
        }
    }

    System::Void CurrencyCreatForm::buttonCreatCurrency_Click(System::Object^ sender, System::EventArgs^ e)
    {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(currencyFilePath);
        std::ofstream file(filePath, std::ios::app);

        std::string currencyName = msclr::interop::marshal_as<std::string>(textBoxCurrencyName->Text);
        std::string currencyRateStr = msclr::interop::marshal_as<std::string>(textBoxCurrencyRate->Text);

        std::string currencyRate = currencyRateStr; // ������� �����, ����� �� ������ ��������
        currencyRate.erase(std::remove(currencyRate.begin(), currencyRate.end(), '.'), currencyRate.end());

        if (!isNumber(currencyRate)) // ���������� currencyRate
        {
            MessageBox::Show("������������ ���� �����!");
            return;
        }

        if (isEditing)
        {
            std::ifstream file(filePath);
            std::vector<std::string> lines;
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    lines.push_back(line);
                }
                file.close();
            }
            if (rowIndexToEdit >= 0 && rowIndexToEdit < static_cast<int>(lines.size()))
            {
                std::string new_line = currencyName + ":" + currencyRate;
                lines[rowIndexToEdit] = new_line;
                std::ofstream outFile(filePath);
                if (outFile.is_open())
                {
                    for (const auto& line : lines)
                    {
                        outFile << line << std::endl;
                    }
                    outFile.close();
                }
                isChanged = true;
                isEditing = false;

                // ��������������� ��������� ��������� ��� ����������
                label_Name->Visible = true;
                label_Rate->Visible = true;
                textBoxCurrencyName->Visible = true;
                textBoxCurrencyRate->Visible = true;
                buttonCreatCurrency->Visible = true;
                dataGridViewCurrencies->Visible = false;
                comboBoxCurrencies->Visible = false;
                button_EditCurrency->Visible = false;
                button_DelCurrency->Visible = false;
                groupBox1->Visible = false;

                LoadCurrenciesToDataGridView();
                LoadCurrenciesToComboBoxes();
                buttonCreatCurrency->Text = "������� ������";
                MessageBox::Show("������ ��������!", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

            }
            else {
                MessageBox::Show("�������� ����� ������ ��� ��������������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        else
        {
            if (file.is_open())
            {
                file << currencyName << ":" << currencyRate << std::endl;
                file.close();
                isChanged = true;
                // ��������������� ��������� ��������� ��� ����������
                label_Name->Visible = true;
                label_Rate->Visible = true;
                textBoxCurrencyName->Visible = true;
                textBoxCurrencyRate->Visible = true;
                buttonCreatCurrency->Visible = true;
                dataGridViewCurrencies->Visible = false;
                comboBoxCurrencies->Visible = false;
                button_EditCurrency->Visible = false;
                button_DelCurrency->Visible = false;
                groupBox1->Visible = false;
                LoadCurrenciesToDataGridView();
                LoadCurrenciesToComboBoxes();
                MessageBox::Show("������ ���������!", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);

            }
            else
            {
                MessageBox::Show("������ �������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        return System::Void();
    }

    System::Void CurrencyCreatForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("����� �����", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    System::Void CurrencyCreatForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }

    System::Void CurrencyCreatForm::button_EditCurrency_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // �������� �������, ���������� � ������
        this->dataGridViewCurrencies->Visible = false;
        this->comboBoxCurrencies->Visible = false;
        this->button_EditCurrency->Visible = false;
        this->groupBox1->Visible = false;

        this->label_Name->Visible = true;
        this->label_Rate->Visible = true;
        this->textBoxCurrencyName->Visible = true;
        this->textBoxCurrencyRate->Visible = true;
        this->buttonCreatCurrency->Visible = true;

        isEditing = true;
        String^ selectedCurrency = comboBoxCurrencies->SelectedItem->ToString();

        // ������� ������, ������� ������ ���� ���������������
        for (int i = 0; i < dataGridViewCurrencies->Rows->Count; ++i) {
            if (dataGridViewCurrencies->Rows[i]->Cells["CurrencyName"]->Value->ToString() == selectedCurrency) {
                rowIndexToEdit = i;
                textBoxCurrencyName->Text = dataGridViewCurrencies->Rows[i]->Cells["CurrencyName"]->Value->ToString();
                textBoxCurrencyRate->Text = dataGridViewCurrencies->Rows[i]->Cells["CurrencyRate"]->Value->ToString();
                break;
            }
        }

        buttonCreatCurrency->Text = "��������!";
    }

    System::Void CurrencyCreatForm::button_DelCurrency_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ selectedCurrency = comboBoxCurrencies->SelectedItem->ToString();
        if (String::IsNullOrEmpty(selectedCurrency)) {
            MessageBox::Show("����������, �������� ������ ��� ��������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        int rowNumber = -1;
        for (int i = 0; i < dataGridViewCurrencies->Rows->Count; i++) {
            if (dataGridViewCurrencies->Rows[i]->Cells["CurrencyName"]->Value->ToString() == selectedCurrency) {
                rowNumber = i;
                break;
            }
        }

        if (rowNumber == -1) {
            MessageBox::Show("�� ������� ����� ������ � ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(currencyFilePath);

        std::ifstream file(filePath);
        std::vector<std::string> lines;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                lines.push_back(line);
            }
            file.close();
        }

        if (rowNumber >= 0 && rowNumber < static_cast<int>(lines.size())) {
            lines.erase(lines.begin() + rowNumber);

            std::ofstream outFile(filePath);
            if (outFile.is_open()) {
                for (const auto& line : lines) {
                    outFile << line << std::endl;
                }
                outFile.close();
            }

            MessageBox::Show("������ ������� �������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadCurrenciesToDataGridView();
            LoadCurrenciesToComboBoxes();

            label_Name->Visible = true;
            label_Rate->Visible = true;
            textBoxCurrencyName->Visible = true;
            textBoxCurrencyRate->Visible = true;
            buttonCreatCurrency->Visible = true;
            dataGridViewCurrencies->Visible = false;
            comboBoxCurrencies->Visible = false;
            button_EditCurrency->Visible = false;
            button_DelCurrency->Visible = false;
            groupBox1->Visible = false;
        }
        else {
            MessageBox::Show("�������� ����� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }
}

