#pragma once
#include <string>
#include <ctime> // ��� ������ �� ��������
#include "Category.h" // ���������� ����� Category
class Transaction
{
public:
    // �����������
    Transaction(std::string name, double amount, std::string date, std::string type, Category* category);

    // ����� ��� ��������� ����� ����������
    std::string getName() const;

    // ����� ��� ��������� ����� ����������
    double getAmount() const;

    // ����� ��� ��������� ���� ����������
    std::string getDate() const;

    // ����� ��� ��������� ���� ����������
    std::string getType() const;

    // ����� ��� ��������� ���������
    Category* getCategory() const;

private:
    std::string name_;
    double amount_;
    std::string date_;
    std::string type_;
    Category* category_;
};

