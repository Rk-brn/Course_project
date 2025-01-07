#pragma once
#include <string>
#include <ctime> // Для работы со временем
#include "Category.h" // Подключаем класс Category
class Transaction
{
public:
    // Конструктор
    Transaction(std::string name, double amount, std::string date, std::string type, Category* category);

    // Метод для получения имени транзакции
    std::string getName() const;

    // Метод для получения суммы транзакции
    double getAmount() const;

    // Метод для получения даты транзакции
    std::string getDate() const;

    // Метод для получения типа транзакции
    std::string getType() const;

    // Метод для получения категории
    Category* getCategory() const;

private:
    std::string name_;
    double amount_;
    std::string date_;
    std::string type_;
    Category* category_;
};

