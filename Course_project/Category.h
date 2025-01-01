#pragma once
#include <string>
    class Category {
    public:
        // �����������
        Category(std::string name, std::string description = "");

        // ����� ��� ��������� ����� ���������
        std::string getName() const;

        // ����� ��� ��������� �������� ���������
        std::string getDescription() const;

        // ����� ��� ��������� �������� ���������
        void setDescription(std::string description);

    private:
        std::string name_;
        std::string description_;
    };


