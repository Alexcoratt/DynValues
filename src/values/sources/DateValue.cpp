#include <algorithm>
#include <stdexcept>
#include <sstream>

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
unsigned int getYearDayCount(unsigned int yearNum) {
	return isLeapYear(yearNum) ? 366 : 365;
}

void subtractYears(unsigned long int daysFromTheBegin, unsigned long int * remains, unsigned int * yearNum) {
	unsigned int yn = 0;
	unsigned long int rmns = daysFromTheBegin;
	unsigned int daysInYear = getYearDayCount(yn);
	while (rmns >= daysInYear) {
		rmns -= daysInYear;
		++yn;
		daysInYear = getYearDayCount(yn);
	}

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

void subtractMonths(unsigned long int daysFromTheYearBegin, unsigned int yearNum, unsigned long int * remains, unsigned int * monthNum) {
	unsigned int mn = 0;
	unsigned long int rmns = daysFromTheYearBegin;
	unsigned int daysInMonth = getMonthDayCount(mn, isLeapYear(yearNum));
	while (rmns >= daysInMonth) {
		rmns -= daysInMonth;
		++mn;
		daysInMonth = getMonthDayCount(mn, isLeapYear(yearNum));
	}

	if (remains)
		*remains = rmns;
	if (monthNum)
		*monthNum = mn;
}

unsigned int DateValue::getMonthNum() const {
	unsigned int yearNum;
	unsigned long int daysRemain;
	subtractYears(_value, &daysRemain, &yearNum);
	unsigned int monthNum;
	subtractMonths(daysRemain, yearNum, nullptr, &monthNum);
	return monthNum;
}

unsigned int DateValue::getDayNum() const {
	unsigned int yearNum;
	unsigned long int daysRemain;
	subtractYears(_value, &daysRemain, &yearNum);
	subtractMonths(daysRemain, yearNum, &daysRemain, nullptr);
	return daysRemain;
}

// setting
unsigned long int sumYear(unsigned long int daysFromTheBegin, unsigned int yearNum) {
	unsigned long int res = daysFromTheBegin;
	while (yearNum--)
		res += getYearDayCount(yearNum);
	return res;
}

void DateValue::setYearNum(unsigned int yearNum) {
	unsigned long int daysRemain;
	subtractYears(_value, &daysRemain, nullptr);
	_value = sumYear(daysRemain, yearNum);
}

unsigned long int sumMonth(unsigned int yearNum, unsigned int monthNum) {
	unsigned long int res = 0;
	while (monthNum > 11) {
		res += getYearDayCount(yearNum++);
		monthNum -= 12;
	}
	while (monthNum--)
		res += getMonthDayCount(monthNum, isLeapYear(yearNum));
	return res;
}

void DateValue::setMonthNum(unsigned int monthNum) {
	unsigned long int daysRemain;
	unsigned int yearNum;
	subtractYears(_value, &daysRemain, &yearNum);
	unsigned long int notMonthDays;
	subtractMonths(daysRemain, yearNum, &notMonthDays, nullptr);
	_value += sumMonth(yearNum, monthNum - 1) - daysRemain + notMonthDays;
}

void DateValue::setDayNum(unsigned int dayNum) {
	_value += dayNum - 1 - getDayNum();
}

// cloning
DateValue * DateValue::getClone() const { return new DateValue{_value}; }

// comparison
bool DateValue::operator<(IValue const & other) const { return _value < other.toUnsignedLongInt(); }

// transformation
std::string DateValue::toString() const {
	std::stringstream sstr;
	sstr << (getDayNum() + 1) << '.' << (getMonthNum() + 1) << '.' << getYearNum();
	return sstr.str();
}

char DateValue::toChar() const { return _value; }
double DateValue::toDouble() const { return _value; }
int DateValue::toInt() const { return _value; }
unsigned long DateValue::toUnsignedLongInt() const { return _value; }
