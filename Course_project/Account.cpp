#include "Account.h"

Account::Account(std::string name, int balance, int transactionCount, std::string description)
{
    this->name = name;
    this->balance = balance;
    this->transactionCount = transactionCount;
    this->description = description;
}

std::string Account::getName() const
{
    return std::string();
}

int Account::getBalance() const
{
    return balance;
}

int Account::getTransactionCount() const
{
    return transactionCount;
}

void Account::setBalance(int balance)
{
    this->balance = balance;
}

void Account::setTransactionCount(int transactionCount)
{
    this->transactionCount = transactionCount;
}

std::string Account::getDescription() const
{
    return std::string();
}
