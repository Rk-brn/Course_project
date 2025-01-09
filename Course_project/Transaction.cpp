#include "Transaction.h"
Transaction::Transaction(std::string name, int amount, std::string date, std::string type, Category* category, std::string typeAccount)
    : name_(name), amount_(amount), date_(date), type_(type), category_(category), typeAccount_(typeAccount) {}

std::string Transaction::getName() const {
    return name_;
}

int Transaction::getAmount() const {
    return amount_;
}

std::string Transaction::getDate() const {
    return date_;
}

std::string Transaction::getType() const {
    return type_;
}

Category* Transaction::getCategory() const {
    return category_;
}


std::string Transaction::getTypeAccount() const {
    return typeAccount_;
}

