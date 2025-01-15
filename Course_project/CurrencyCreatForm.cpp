
#include "CurrencyCreatForm.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <algorithm>
#include <regex>

namespace Courseproject {
    const char* CURRENCY_FILE_NAME = "currencies.txt";

    // ������� ��� ��������, �������� �� ������ ���������� ������ ������ (������ ����������� ������)
    bool isValidCurrencyRate(const std::string& str)
    {
        std::regex pattern("^\\d+\\.\\d{2}$");
        return std::regex_match(str, pattern);
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


        // �������������� ������ �������� (�� �����������)
        dataGridViewCurrencies->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

        // ������ ����������� ������ ��� ������� �������
        dataGridViewCurrencies->Columns[0]->MinimumWidth = 150;

        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(currencyFilePath);
        std::ifstream file(filePath);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                size_t separatorPos = line.find(':');
                if (separatorPos != std::string::npos) {
                    std::string name = line.substr(0, separatorPos);
                    std::string rateStr = line.substr(separatorPos + 1);

                    double rate = 0.0;
                    try {
                        rate = std::stod(rateStr) / 100.0;
                    }
                    catch (const std::invalid_argument& e) {

                        System::String^ message = gcnew System::String("������ �������������� ����� �����: ") + gcnew System::String(e.what());
                        MessageBox::Show(message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        continue;
                    }
                    catch (const std::out_of_range& e) {
                        System::String^ message = gcnew System::String("������ ��������� ����� �����: ") + gcnew System::String(e.what());
                        MessageBox::Show(message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        continue;
                    }
                    System::String^ formattedRate = String::Format("{0:F2}", rate);
                    dataGridViewCurrencies->Rows->Add(gcnew System::String(name.c_str()), formattedRate);
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

        if (String::IsNullOrEmpty(textBoxCurrencyName->Text) || String::IsNullOrEmpty(textBoxCurrencyRate->Text)) {
            MessageBox::Show("����������, ��������� ��� ����!", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return; // ����� �� �������, ���� ���� ������.
        }

        std::string currencyName = msclr::interop::marshal_as<std::string>(textBoxCurrencyName->Text);
        std::string currencyRateStr = msclr::interop::marshal_as<std::string>(textBoxCurrencyRate->Text);

        if (!isValidCurrencyRate(currencyRateStr))
        {
            MessageBox::Show("������������ ���� �����. ������� ����� � ������� �����.����� (��������, 123.45)", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // ����������� ������ � ������ � �����
        double rate = std::stod(currencyRateStr) * 100.0;
        std::string currencyRate = std::to_string(static_cast<int>(std::round(rate)));

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
        this->label_del_ch->Visible = false;
        this->label1->Visible = true;
        this->label_Name->Visible = true;
        this->label_Rate->Visible = true;
        this->textBoxCurrencyName->Visible = true;
        this->textBoxCurrencyRate->Visible = true;
        this->buttonCreatCurrency->Visible = true;

        isEditing = true;
        if (comboBoxCurrencies->SelectedItem == nullptr) {
            MessageBox::Show("����������, �������� ������ ��� ��������������.", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return; // ����� �� �������, ���� ������ �� �������.
        }

        String^ selectedCurrency = comboBoxCurrencies->SelectedItem->ToString();

        // ������� ������, ������� ������ ���� ���������������
        for (int i = 0; i < dataGridViewCurrencies->Rows->Count; ++i) {
            if (dataGridViewCurrencies->Rows[i]->Cells["CurrencyName"]->Value->ToString() == selectedCurrency) {
                rowIndexToEdit = i;
                textBoxCurrencyName->Text = dataGridViewCurrencies->Rows[i]->Cells["CurrencyName"]->Value->ToString();
                // �������� ���� �� DataGridView
                double rate = std::stod(msclr::interop::marshal_as<std::string>(dataGridViewCurrencies->Rows[i]->Cells["CurrencyRate"]->Value->ToString()));


                // ����������� ����� ��� ���������� � ���� 1111.11
                System::String^ formattedRate = String::Format("{0:F2}", rate);

                
                textBoxCurrencyRate->Text = formattedRate;

                break;
            }
        }

        buttonCreatCurrency->Text = "��������!";
    }

    System::Void CurrencyCreatForm::button_DelCurrency_Click(System::Object^ sender, System::EventArgs^ e)
    {

        if (comboBoxCurrencies->SelectedItem == nullptr) {
            MessageBox::Show("����������, �������� ������ ��� ��������.", "��������������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return; // ����� �� �������, ���� ������ �� �������.
        }


        String^ selectedCurrency = comboBoxCurrencies->SelectedItem->ToString();

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
            label_del_ch->Visible = false;
            dataGridViewCurrencies->Visible = false;
            comboBoxCurrencies->Visible = false;
            button_EditCurrency->Visible = false;
            button_DelCurrency->Visible = false;
            groupBox1->Visible = false;
            this->Close();
        }
        else {
            MessageBox::Show("�������� ����� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

    }
}
