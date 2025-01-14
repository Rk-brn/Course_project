#include "CurrencyConverterForm.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>

namespace Courseproject {
    CurrencyConverterForm::CurrencyConverterForm(void)
    {
        InitializeComponent();
        dataGridViewConversions->Columns->Add("Balance", "Áàëàíñ");
        dataGridViewConversions->Columns->Add("ConvertedBalance", "Êîíâåðòèðîâàííûé áàëàíñ");
        dataGridViewConversions->Columns->Add("Rate", "Êóðñ");
        LoadAccountsToComboBox();
        LoadCurrenciesToComboBox();
    }
    void CurrencyConverterForm::LoadAccountsToComboBox() {
        comboBoxAccounts->Items->Clear();
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, balanceStr, count, description;
                if (std::getline(iss, name, ':') && std::getline(iss, balanceStr, ':') && std::getline(iss, count, ':') && std::getline(iss, description, ','))
                {
                    std::string accountName;
                    std::istringstream nameStream(name);
                    std::getline(nameStream, accountName, ':');
                    comboBoxAccounts->Items->Add(gcnew String(accountName.c_str()));
                }
            }
            file.close();
        }
    }
    void CurrencyConverterForm::LoadCurrenciesToComboBox() {
        comboBoxCurrencies->Items->Clear();
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("currencies.txt"));
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string currencyName, currencyRate;
                if (std::getline(iss, currencyName, ':') && std::getline(iss, currencyRate, '\n'))
                {
                    comboBoxCurrencies->Items->Add(gcnew String(currencyName.c_str()));
                }
            }
            file.close();
        }
    }
    double CurrencyConverterForm::GetAccountBalance(const std::string& accountName) {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        int balance = 0;
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name, balanceStr, count, description;
                if (std::getline(iss, name, ':')) {
                    std::istringstream nameStream(name);
                    std::string currentAccountName;
                    std::getline(nameStream, currentAccountName, ':');
                    if (currentAccountName == accountName)
                    {
                        if (std::getline(iss, balanceStr, ':'))
                        {
                            try {
                                balance = std::stoi(balanceStr);
                            }
                            catch (const std::invalid_argument& e)
                            {
                                std::cerr << "Error parsing initial balance for account:" << accountName << std::endl;
                            }
                            catch (const std::out_of_range& e)
                            {
                                std::cerr << "Error number out of range" << std::endl;
                            }
                            break;
                        }
                    }
                }
            }
            file.close();
        }
        return balance;
    }
    std::vector<Currency> CurrencyConverterForm::LoadCurrenciesFromFile() {
        std::vector<Currency> currencies;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("currencies.txt"));
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string currencyName, currencyRate;
                if (std::getline(iss, currencyName, ':') && std::getline(iss, currencyRate, '\n'))
                {
                    try
                    {
                        int rate = std::stoi(currencyRate);
                        currencies.emplace_back(currencyName, rate);
                    }
                    catch (const std::invalid_argument& e)
                    {
                        std::cerr << "Error parsing currency rate for: " << currencyName << std::endl;
                    }
                    catch (const std::out_of_range& e)
                    {
                        std::cerr << "Error number out of range: " << currencyName << std::endl;
                    }
                }
            }
            file.close();
        }
        return currencies;
    }
    void CurrencyConverterForm::LoadConversionResult(const std::string& accountName, const std::string& currencyName)
    {
        dataGridViewConversions->Rows->Clear();
       
        int balance = GetAccountBalance(accountName);
        std::vector<Currency> currencies = LoadCurrenciesFromFile();
        for (auto& currency : currencies) {
            System::String^ currencyNameSystem = gcnew System::String(currency.getName().c_str());
            System::String^ targetCurrencyNameSystem = gcnew System::String(currencyName.c_str());
            if (currencyNameSystem->Trim() == targetCurrencyNameSystem->Trim())
            {
                double kurs = currency.getRate() / 100.0;
                double convertedBalance = static_cast<double>(balance) / kurs;
                int rowIndex = dataGridViewConversions->Rows->Add();
                dataGridViewConversions->Rows[rowIndex]->Cells["Balance"]->Value = gcnew String(std::to_string(balance).c_str());
                dataGridViewConversions->Rows[rowIndex]->Cells["ConvertedBalance"]->Value = gcnew String(System::String::Format("{0:F2}", convertedBalance));
                dataGridViewConversions->Rows[rowIndex]->Cells["Rate"]->Value = gcnew String(std::to_string(kurs).c_str());
                break;
            }
        }

    }
   


    System::Void CurrencyConverterForm::äîáàâèòüÂàëþòóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CurrencyCreatForm^ creat = gcnew CurrencyCreatForm();
        creat->ShowDialog();
        LoadCurrenciesToComboBox();
        return System::Void();
    }

    System::Void CurrencyConverterForm::èíôîðìàèöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Áóäåò òåêñò", "Èíôîðìàöèÿ", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }

    System::Void CurrencyConverterForm::âåðíóòüñÿÊÑ÷åòàìToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }

    System::Void CurrencyConverterForm::buttonConversion_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (comboBoxAccounts->SelectedItem != nullptr && comboBoxCurrencies->SelectedItem != nullptr) {
            System::String^ selectedAccount = comboBoxAccounts->SelectedItem->ToString();
            System::String^ selectedCurrency = comboBoxCurrencies->SelectedItem->ToString();
            msclr::interop::marshal_context context;
            std::string accountName = context.marshal_as<std::string>(selectedAccount);
            std::string currencyName = context.marshal_as<std::string>(selectedCurrency);
            LoadConversionResult(accountName, currencyName);
        }
        return System::Void();
    }
    System::Void CurrencyConverterForm::ðåäàêòèðîâàòüÂàëþòóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CurrencyCreatForm^ change = gcnew CurrencyCreatForm();
        change->label_Name->Visible = false;
        change->label_Rate->Visible = false;
        change->textBoxCurrencyName->Visible = false;
        change->textBoxCurrencyRate->Visible = false;
        change->buttonCreatCurrency->Visible = false;
        change->dataGridViewCurrencies->Visible = true;
        change->comboBoxCurrencies->Visible = true;
        change->button_EditCurrency->Visible = true;
        change->button_DelCurrency->Visible = true;
        change->groupBox1->Visible = true;
        change->ShowDialog();
        LoadCurrenciesToComboBox();
        return System::Void();
    }
    System::Void CurrencyConverterForm::óäàëèòüÂàëþòóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CurrencyCreatForm^ del = gcnew CurrencyCreatForm();
        del->label_Name->Visible = false;
        del->label_Rate->Visible = false;
        del->textBoxCurrencyName->Visible = false;
        del->textBoxCurrencyRate->Visible = false;
        del->buttonCreatCurrency->Visible = false;
        del->dataGridViewCurrencies->Visible = true;
        del->comboBoxCurrencies->Visible = true;
        del->button_EditCurrency->Visible = true;
        del->button_DelCurrency->Visible = true;
        del->groupBox1->Visible = true;
        del->ShowDialog();
        LoadCurrenciesToComboBox();
        return System::Void();
    }
}