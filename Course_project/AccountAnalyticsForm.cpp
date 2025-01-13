#include "AccountAnalyticsForm.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <map>
#include <numeric> //Для std::accumulate
#include "Category.h"

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


    // Функция загрузки транзакций из файла
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
                        // Создаем новый объект Category (можно добавить логику для загрузки категорий, если требуется)
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

            // Загружаем транзакции
            std::vector<Transaction*> transactions = LoadTransactionsFromFile();

            // Фильтруем транзакции по выбранному счету
            std::vector<Transaction*> filteredTransactions;
            for (const auto& transaction : transactions) {
                if (transaction->getTypeAccount() == accountName) {
                    filteredTransactions.push_back(transaction);
                }
            }

            // Рассчитываем доходы и расходы
            double totalIncome = 0;
            double totalExpense = 0;

            for (const auto& transaction : filteredTransactions) {
                if (transaction->getType() == "Доход") {
                    totalIncome += transaction->getAmount();
                }
                else if (transaction->getType() == "Расход") {
                    totalExpense += transaction->getAmount();
                }
            }

            // Получаем текущий баланс счета
            double balance = GetAccountBalance(accountName);
            // Проверяем, является ли счет профицитным или дефицитным
            if (balance >= 0) {
                labelBalanceStatus->Text = "Счет профицитный";
            }
            else {
                labelBalanceStatus->Text = "Счет дефицитный";
            }

            // Очищаем график перед добавлением данных
            chartAnalytics->Series->Clear();
            // Создаем серию данных для круговой диаграммы
            Series^ series = gcnew Series("Доходы/Расходы");
            series->ChartType = SeriesChartType::Pie;
            // Правильное добавление данных с использованием String::Format
            series->Points->AddXY(String::Format("Доходы ({0})", totalIncome.ToString()), totalIncome);
            series->Points->AddXY(String::Format("Расходы ({0})", totalExpense.ToString()), totalExpense);




            // Добавляем серию данных на график
            chartAnalytics->Series->Add(series);
            for (Transaction* transaction : transactions)
                delete transaction;
        }
        return System::Void();
    }
}