#pragma once
#include <string>
    class Category {
    public:
        // Конструктор
        Category(std::string name, std::string description = "");

        // Метод для получения имени категории
        std::string getName() const;

        // Метод для получения описания категории
        std::string getDescription() const;

        // Метод для изменения описания категории
        void setDescription(std::string description);

    private:
        std::string name_;
        std::string description_;
    };


