#include "Transaction.h"
Transaction::Transaction(std::string name, double amount, std::string date, std::string type, Category* category)
    : name_(name), amount_(amount), date_(date), type_(type), category_(category) {}

std::string Transaction::getName() const {
    return name_;
}

double Transaction::getAmount() const {
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
