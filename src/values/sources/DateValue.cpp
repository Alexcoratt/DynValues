#include <algorithm>
#include <stdexcept>

#include "DateValue.hpp"

DateValue::DateValue(unsigned long int const & value) : _value(value) {}
DateValue::DateValue(DateValue const & other) : _value(other._value) {}

DateValue & DateValue::operator=(DateValue const & other) {
	if (this != &other) {
		DateValue tmp{other};
		swap(tmp);
	}
	return *this;
}

DateValue::~DateValue() {}

void DateValue::swap(DateValue & other) { std::swap(_value, other._value); }

// setting
void DateValue::setYearNum(unsigned int yearNum) {}
void DateValue::setMonthNum(unsigned int monthNum) {}
void DateValue::setDayNum(unsigned int dayNum) {}

// getting
bool isLeapYear(unsigned int yearNum) {
	if (yearNum % 400 == 0)
		return true;
	if (yearNum % 100 == 0)
		return false;
	if (yearNum % 4 == 0)
		return true;
	return false;
}

void subtractYears(unsigned long int const & daysFromTheBegin, unsigned long int * remains, unsigned int * yearNum) {
	unsigned int yn = 0;
	unsigned long int rmns = daysFromTheBegin;
	unsigned int daysInYear;
	do {
		daysInYear = isLeapYear(yn) ? 366 : 365;
		rmns -= daysInYear;
		++yn;
	} while (rmns >= daysInYear);

	if (remains)
		*remains = rmns;
	if (yearNum)
		*yearNum = yn;
}

unsigned int DateValue::getYearNum() const {
	unsigned int yearNum;
	subtractYears(_value, nullptr, &yearNum);
	return yearNum;
}

constexpr unsigned int const months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned int getMonthDayCount(unsigned int monthNum, bool isLeap) {
	if (monthNum > 11)
		throw std::invalid_argument("month number cannot be more than 11 (beginning from 0), provided: " + std::to_string(monthNum));

	unsigned int res = months[monthNum];
	if (monthNum == 1 && isLeap)
		++res;
	return res;
}

void subtractMonths(unsigned long int daysFromTheYearBegin, bool isLeap, unsigned long int * remains, unsigned int * monthNum) {
	unsigned int mn = 0;
	unsigned long int rmns = daysFromTheYearBegin;
	unsigned int daysInMonth;
	do {
		daysInMonth = getMonthDayCount(mn, isLeap)
	}
}

unsigned int DateValue::getMonthNum() const {}

unsigned int DateValue::getDayNum() const {}
