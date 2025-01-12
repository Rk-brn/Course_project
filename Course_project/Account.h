#pragma once
#include <string>
#include <vector>
class Account
{private:
    std::string name;
    int balance;
    int transactionCount;
    std::string description;
    public:
        Account(std::string name, int balance, int transactionCount, std::string description);
        std::string getName() const;
        std::string getDescription() const;
        int getBalance() const;
        int getTransactionCount() const;
        void setBalance(int balance);
        void setTransactionCount(int transactionCount);

    };
extern std::vector<Account> accounts;

