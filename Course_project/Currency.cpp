#include "Currency.h"

Currency::Currency(std::string name, int rate)
{
	this->Name = name;
	this->Rate = rate;
}

std::string Currency::getName() const
{
	return Name;
}

int Currency::getRate() const
{
	return Rate;
}