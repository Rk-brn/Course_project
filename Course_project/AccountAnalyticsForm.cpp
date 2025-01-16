#include "AccountAnalyticsForm.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <map>
#include <numeric> //Для std::accumulate
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
        if (comboBoxAccounts->SelectedIndex == -1) {
            MessageBox::Show("Пожалуйста, выберите счёт из списка.", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return; // Завершаем выполнение метода
        }
        else {
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
            if (filteredTransactions.empty())
            {
                MessageBox::Show("Нет транзакций для данного счета.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
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
                // Форматирование дохода и расхода
                double formattedIncome = static_cast<double>(totalIncome) / 100.0;
                double formattedExpenses = static_cast<double>(totalExpense) / 100.0;
                // расчет общего кол-ва денег
                double total = totalIncome + totalExpense;

                // Рассчитываем проценты
                double incomePercentage = 0.0;
                double expensesPercentage = 0.0;
                if (total > 0) {
                    incomePercentage = (totalIncome / total) * 100.0;
                    expensesPercentage = (totalExpense / total) * 100.0;
                }

                // Форматируем проценты
                System::String^ formattedIncomePercentage = String::Format("{0:F2}", incomePercentage);
                System::String^ formattedExpensesPercentage = String::Format("{0:F2}", expensesPercentage);

                // Получаем текущий баланс счета
                double balance = GetAccountBalance(accountName);
                // Проверяем, является ли счет профицитным или дефицитным
                if (balance >= 0) {
                    labelBalanceStatus->Text = "Ваш тип счёта: профицитный";
                }
                else {
                    labelBalanceStatus->Text = "Ваш тип счёта: дефицитный";
                }

                // Очищаем график перед добавлением данных
                chartAnalytics->Series->Clear();
                // Создаем серию данных для круговой диаграммы
                Series^ pieSeries = gcnew Series("Доходы/Расходы");
                pieSeries->ChartType = SeriesChartType::Pie;

                pieSeries->Points->AddXY(String::Format("Доходы ({0}%)", formattedIncomePercentage), totalIncome); // Проценты
                pieSeries->Points->AddXY(String::Format("Расходы ({0}%)", formattedExpensesPercentage), totalExpense); // Проценты

                // Добавляем серию данных на график
                chartAnalytics->Series->Add(pieSeries);

                // Подготавливаем данные для гистограммы
                chartMonthly->Series->Clear();
                Series^ monthlySeriesIncome = gcnew Series(String::Format("Доходы ({0:F2})", formattedIncome)); // Форматированный вывод
                Series^ monthlySeriesExpense = gcnew Series(String::Format("Расходы ({0:F2})", formattedExpenses));
                monthlySeriesIncome->ChartType = SeriesChartType::Column;
                monthlySeriesExpense->ChartType = SeriesChartType::Column;
                // Создаем карту для хранения данных о доходах и расходах по месяцам
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


                    if (transaction->getType() == "Доход")
                    {
                        monthlyIncomes[month] += transaction->getAmount();
                    }
                    else if (transaction->getType() == "Расход")
                    {
                        monthlyExpenses[month] += transaction->getAmount();
                    }
                }

                // Добавляем данные в серии
                for (const auto& pair : monthlyIncomes)
                {
                    monthlySeriesIncome->Points->AddXY(gcnew String(pair.first.c_str()), pair.second / 100.0); // Выводим значения с точкой
                }
                for (const auto& pair : monthlyExpenses)
                {
                    monthlySeriesExpense->Points->AddXY(gcnew String(pair.first.c_str()), pair.second / 100.0); // Выводим значения с точкой
                }

                // Добавляем серии на график
                chartMonthly->Series->Add(monthlySeriesIncome);
                chartMonthly->Series->Add(monthlySeriesExpense);
            }
        }
    }
    System::Void AccountAnalyticsForm::информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("В данном окне отображается аналитика выбранного счёта.\nЧтобы просмотреть аналитику, выберите счёт из списка 'Выберите счёт:'.\nПосле этого нажмите кнопку 'Провести аналитику', чтобы обновить график с балансом счёта.\nЧтобы очистить графики и убрать выбранный счёт, нажмите кнопку 'Очистить блоки'.", "Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return System::Void();
    }
    System::Void AccountAnalyticsForm::button_clear_Click(System::Object^ sender, System::EventArgs^ e)
    {
        comboBoxAccounts->SelectedIndex = -1;
        chartAnalytics->Series->Clear();
        chartMonthly->Series->Clear();
        labelBalanceStatus->Text = "Тип вашего счёта!";
        return System::Void();
    }
    System::Void AccountAnalyticsForm::вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
        return System::Void();
    }
}