#include "CurrencyCreatForm.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <algorithm>

namespace Courseproject {
    bool isNumber(const std::string& str) 
    {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }

    CurrencyCreatForm::CurrencyCreatForm(void)
    {
        InitializeComponent();
    }
    
    System::Void CurrencyCreatForm::buttonCreatCurrency_Click(System::Object^ sender, System::EventArgs^ e)
    {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("currencies.txt"));
        std::ofstream file(filePath, std::ios::app);
        std::string currencyName = context.marshal_as<std::string>(textBoxCurrencyName->Text);
        std::string currencyRateStr = context.marshal_as<std::string>(textBoxCurrencyRate->Text);

        //������� �����
        currencyRateStr.erase(std::remove(currencyRateStr.begin(), currencyRateStr.end(), '.'), currencyRateStr.end());

        if (!isNumber(currencyRateStr))
        {
            MessageBox::Show("������������ ���� �����!");
            return;
        }
        if (file.is_open())
        {
            file << currencyName << ":" << currencyRateStr << std::endl;
            file.close();
            MessageBox::Show("������ ���������!");
            this->Close();
        }
        else
        {
            MessageBox::Show("������ ��� �������� �����!");
        }
        return System::Void();
    }

    System::Void CurrencyCreatForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("����� �����", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }

    System::Void CurrencyCreatForm::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
}