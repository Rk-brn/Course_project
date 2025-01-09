#pragma once
#include <string>
#include <ctime> // ��� ������ �� ��������
#include "Category.h" // ���������� ����� Category
class Transaction
{
public:
    // �����������
    Transaction(std::string name, int amount, std::string date, std::string type, Category* category, std::string typeAccount);

    // ����� ��� ��������� ����� ����������
    std::string getName() const;

    // ����� ��� ��������� ����� ����������
    int getAmount() const;

    // ����� ��� ��������� ���� ����������
    std::string getDate() const;

    // ����� ��� ��������� ���� ����������
    std::string getType() const;

    // ����� ��� ��������� ���������
    Category* getCategory() const;

    std::string getTypeAccount() const;

private:
    std::string name_;
    int amount_;
    std::string date_;
    std::string type_;
    Category* category_;
    std::string typeAccount_;
};

