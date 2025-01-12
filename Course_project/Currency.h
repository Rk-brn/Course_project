#pragma once
#include <string>
class Currency
{
private:
	std::string Name;
	int Rate;
public:
	Currency(std::string name, int rate);
	std::string getName() const;
	int getRate() const;
};

