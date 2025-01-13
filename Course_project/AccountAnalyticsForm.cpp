#include "AccountAnalyticsForm.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <map>
#include <numeric> //��� std::accumulate
#include "Category.h"
#include <ctime>
#include <iomanip>



using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;

namespace Courseproject {

    AccountAnalyticsForm::AccountAnalyticsForm(void)
    {
        InitializeComponent();
        LoadAccountsToComboBox();
    }

    void AccountAnalyticsForm::LoadAccountsToComboBox() {
        comboBoxAccounts->Items->Clear();
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew String("account.txt"));
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


    // ������� �������� ���������� �� �����
    std::vector<Transaction*> AccountAnalyticsForm::LoadTransactionsFromFile() {
        std::vector<Transaction*> transactions;
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew String("transactions.txt"));
        std::ifstream file(filePath);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string shop, amountStr, date, type, description, accountName;
                if (std::getline(iss, shop, ';') &&
                    std::getline(iss, amountStr, ';') &&
                    std::getline(iss, date, ';') &&
                    std::getline(iss, type, ';') &&
                    std::getline(iss, description, ';') &&
                    std::getline(iss, accountName, ';')) {
                    try {
                        int amount = std::stoi(amountStr);
                        // ������� ����� ������ Category (����� �������� ������ ��� �������� ���������, ���� ���������)
                        Category* category = new Category(description);
                        Transaction* transaction = new Transaction(shop, amount, date, type, category, accountName);
                        transactions.push_back(transaction);
                    }
                    catch (const std::invalid_argument& e) {
                        std::cerr << "Error parsing amount for transaction:" << std::endl;
                    }
                }
            }
            file.close();
        }
        return transactions;
    }

    double AccountAnalyticsForm::GetAccountBalance(const std::string& accountName) {
        msclr::interop::marshal_context context;
        std::string filePath = context.marshal_as<std::string>(gcnew System::String("account.txt"));
        std::ifstream file(filePath);
        double balance = 0;
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
                                balance = std::stod(balanceStr);
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
    System::Void AccountAnalyticsForm::buttonAnalitics_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (comboBoxAccounts->SelectedItem != nullptr)
        {
            System::String^ selectedAccount = comboBoxAccounts->SelectedItem->ToString();
            msclr::interop::marshal_context context;
            std::string accountName = context.marshal_as<std::string>(selectedAccount);

            // ��������� ����������
            std::vector<Transaction*> transactions = LoadTransactionsFromFile();

            // ��������� ���������� �� ���������� �����
            std::vector<Transaction*> filteredTransactions;
            for (const auto& transaction : transactions) {
                if (transaction->getTypeAccount() == accountName) {
                    filteredTransactions.push_back(transaction);
                }
            }

            // ������������ ������ � �������
            if (filteredTransactions.empty())
            {
                MessageBox::Show("��� ���������� ��� ������� �����.", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                double totalIncome = 0;
                double totalExpense = 0;

                for (const auto& transaction : filteredTransactions) {
                    if (transaction->getType() == "�����") {
                        totalIncome += transaction->getAmount();
                    }
                    else if (transaction->getType() == "������") {
                        totalExpense += transaction->getAmount();
                    }
                }

                // �������� ������� ������ �����
                double balance = GetAccountBalance(accountName);
                // ���������, �������� �� ���� ����������� ��� ����������
                if (balance >= 0) {
                    labelBalanceStatus->Text = "���� �����������";
                }
                else {
                    labelBalanceStatus->Text = "���� ����������";
                }

                // ������� ������ ����� ����������� ������
                chartAnalytics->Series->Clear();
                // ������� ����� ������ ��� �������� ���������
                Series^ pieSeries = gcnew Series("������/�������");
                pieSeries->ChartType = SeriesChartType::Pie;
                pieSeries->Points->AddXY(String::Format("������ ({0})", totalIncome.ToString()), totalIncome);
                pieSeries->Points->AddXY(String::Format("������� ({0})", totalExpense.ToString()), totalExpense);
                // ��������� ����� ������ �� ������
                chartAnalytics->Series->Add(pieSeries);

                // �������������� ������ ��� �����������
                chartMonthly->Series->Clear();
                Series^ monthlySeriesIncome = gcnew Series("������");
                Series^ monthlySeriesExpense = gcnew Series("�������");
                monthlySeriesIncome->ChartType = SeriesChartType::Column;
                monthlySeriesExpense->ChartType = SeriesChartType::Column;

                // ������� ����� ��� �������� ������ � ������� � �������� �� �������
                std::map<std::string, double> monthlyIncomes;
                std::map<std::string, double> monthlyExpenses;

                for (const auto& transaction : filteredTransactions) {
                    std::tm t{};
                    std::istringstream ss(transaction->getDate());
                    ss >> std::get_time(&t, "%d.%m.%Y");

                    if (ss.fail()) {
                        std::cerr << "failed to parse time string\n";
                    }

                    char month_str[10];
                    std::strftime(month_str, sizeof(month_str), "%b %Y", &t);
                    std::string month(month_str);


                    if (transaction->getType() == "�����")
                    {
                        monthlyIncomes[month] += transaction->getAmount();
                    }
                    else if (transaction->getType() == "������")
                    {
                        monthlyExpenses[month] += transaction->getAmount();
                    }

                }
                // ��������� ������ � �����
                for (const auto& pair : monthlyIncomes)
                {
                    monthlySeriesIncome->Points->AddXY(gcnew String(pair.first.c_str()), pair.second);
                }
                for (const auto& pair : monthlyExpenses)
                {
                    monthlySeriesExpense->Points->AddXY(gcnew String(pair.first.c_str()), pair.second);
                }

                // ��������� ����� �� ������
                chartMonthly->Series->Add(monthlySeriesIncome);
                chartMonthly->Series->Add(monthlySeriesExpense);

                for (Transaction* transaction : transactions)
                    delete transaction;
            }
            return System::Void();
        }
    }
}