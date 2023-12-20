#include <algorithm>
#include <stdexcept>
#include <sstream>

#include <iostream>

#include "DateValue.hpp"

#define DAYS_IN_400_YEARS 146097

namespace DateValue_auxillary {
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
		unsigned int yn = daysFromTheBegin / DAYS_IN_400_YEARS * 400;
		unsigned long int rmns = daysFromTheBegin % DAYS_IN_400_YEARS;
		unsigned int daysInYear = getYearDayCount(yn);
		while (rmns >= daysInYear) {
			rmns -= daysInYear;
			++yn;
			daysInYear = getYearDayCount(yn);
			//std::cout << yn << ' ' << rmns << std::endl;
		}

		if (remains)
			*remains = rmns;
		if (yearNum)
			*yearNum = yn;
	}

	constexpr unsigned int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

	unsigned long int sumYear(unsigned long int daysFromTheBegin, unsigned int yearNum) {
		unsigned long int res = daysFromTheBegin;
		while (yearNum--)
			res += getYearDayCount(yearNum);
		return res;
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
}

DateValue::DateValue(unsigned long int const & value) : _value(value) {}
DateValue::DateValue(unsigned int dayNum, unsigned int monthNum, unsigned int yearNum) : _value(0) { set(dayNum, monthNum, yearNum); }
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

unsigned int DateValue::getYearNum() const {
	unsigned int yearNum;
	DateValue_auxillary::subtractYears(_value, nullptr, &yearNum);
	return yearNum;
}

unsigned int DateValue::getMonthNum() const {
	unsigned int yearNum;
	unsigned long int daysRemain;
	DateValue_auxillary::subtractYears(_value, &daysRemain, &yearNum);
	unsigned int monthNum;
	DateValue_auxillary::subtractMonths(daysRemain, yearNum, nullptr, &monthNum);
	return monthNum;
}

unsigned int DateValue::getDayNum() const {
	unsigned int yearNum;
	unsigned long int daysRemain;
	DateValue_auxillary::subtractYears(_value, &daysRemain, &yearNum);
	DateValue_auxillary::subtractMonths(daysRemain, yearNum, &daysRemain, nullptr);
	return daysRemain;
}

// setting
void DateValue::setYearNum(unsigned int yearNum) {
	unsigned long int daysRemain;
	DateValue_auxillary::subtractYears(_value, &daysRemain, nullptr);
	_value = DateValue_auxillary::sumYear(daysRemain, yearNum);
}

void DateValue::setMonthNum(unsigned int monthNum) {
	unsigned long int daysRemain;
	unsigned int yearNum;
	DateValue_auxillary::subtractYears(_value, &daysRemain, &yearNum);
	unsigned long int notMonthDays;
	DateValue_auxillary::subtractMonths(daysRemain, yearNum, &notMonthDays, nullptr);
	_value += DateValue_auxillary::sumMonth(yearNum, monthNum - 1) - daysRemain + notMonthDays;
}

void DateValue::setDayNum(unsigned int dayNum) {
	_value += dayNum - 1 - getDayNum();
}

void DateValue::set(unsigned int dayNum, unsigned int monthNum, unsigned int yearNum) {
	setYearNum(yearNum);
	setMonthNum(monthNum);
	setDayNum(dayNum);
}

void DateValue::setDaysFromTheBegin(unsigned long int dayNum) { _value = dayNum; }

// cloning
DateValue * DateValue::getClone() const { return new DateValue{_value}; }

// comparison
bool DateValue::operator<(AbstractValue const & other) const { return _value < other.toUnsignedLongInt(); }

// transformation
std::string DateValue::toString() const {
	unsigned long int dayNum;
	unsigned int yearNum;
	unsigned int monthNum;
	DateValue_auxillary::subtractYears(_value, &dayNum, &yearNum);
	DateValue_auxillary::subtractMonths(dayNum, yearNum, &dayNum, &monthNum);
	std::stringstream sstr;
	sstr << (dayNum + 1) << '.' << (monthNum + 1) << '.' << yearNum;
	return sstr.str();
}

char DateValue::toChar() const { return _value; }
double DateValue::toDouble() const { return _value; }
int DateValue::toInt() const { return _value; }
unsigned long DateValue::toUnsignedLongInt() const { return _value; }

// arithmetic operations
DateValue * DateValue::add(AbstractValue const * other) const { return new DateValue(_value + other->toUnsignedLongInt()); }
DateValue * DateValue::sub(AbstractValue const * other) const { return new DateValue(_value - other->toUnsignedLongInt()); }
DateValue * DateValue::mul(AbstractValue const * other) const { return new DateValue(_value * other->toUnsignedLongInt()); }
DateValue * DateValue::div(AbstractValue const * other) const { return new DateValue(_value / other->toUnsignedLongInt()); }
