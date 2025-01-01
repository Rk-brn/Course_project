#include "Category.h"
Category::Category(std::string name, std::string description)
    : name_(name), description_(description)
{
    this->name_ = name;
    this->description_ = description;
}

std::string Category::getName() const {
    return name_;
}

std::string Category::getDescription() const {
    return description_;
}

void Category::setDescription(std::string description) {
    description_ = description;
}