#pragma once
#include <string>
#include <vector>
class Account
{private:
    std::string name;
    int balance;
    int transactionCount;

    public:
        Account(std::string name, int balance, int transactionCount = 0);
        std::string getName() const;
        int getBalance() const;
        int getTransactionCount() const;
        void setBalance(int balance);
        void setTransactionCount(int transactionCount);

    };
extern std::vector<Account> accounts;

