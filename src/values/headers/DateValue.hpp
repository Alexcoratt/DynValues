#ifndef DATE_VALUE_HPP
#define DATE_VALUE_HPP

#include "AbstractValue.hpp"

class DateValue : public AbstractValue {
private:
	unsigned long int _value;

public:
	DateValue(unsigned long int const & value = 0);
	DateValue(unsigned int dayNum, unsigned int monthNum, unsigned int yearNum);
	DateValue(DateValue const & other);
	DateValue & operator=(DateValue const & other);
	~DateValue();

	void swap(DateValue & other);

	// getting
	unsigned int getYearNum() const;
	unsigned int getMonthNum() const;
	unsigned int getDayNum() const;

	// setting
	void setYearNum(unsigned int yearNum);
	void setMonthNum(unsigned int monthNum);
	void setDayNum(unsigned int dayNum);

	void set(unsigned int dayNum, unsigned int monthNum, unsigned int yearNum);
	void setDaysFromTheBegin(unsigned long int dayNum);

	// cloning
	DateValue * getClone() const override;

	// comparison
	bool operator<(AbstractValue const &) const override;

	// vector methods are unappliable

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isDate() const override { return true; }

	std::string getTypeName() const override { return "DateValue"; }

	// arithmetic operations
	DateValue * add(AbstractValue const * other) const override;
	DateValue * sub(AbstractValue const * other) const override;
	DateValue * mul(AbstractValue const * other) const override;
	DateValue * div(AbstractValue const * other) const override;
};

#endif
