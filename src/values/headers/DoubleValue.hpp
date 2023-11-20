#ifndef DOUBLE_VALUE_HPP
#define DOUBLE_VALUE_HPP

#include "IValue.hpp"

class DoubleValue : public IValue {
private:
	double _value;

public:
	DoubleValue(double);
	DoubleValue(IValue const &);
	DoubleValue & operator=(IValue const &);
	~DoubleValue();

	void swap(DoubleValue &);

	DoubleValue * getClone() const;

	bool operator<(IValue const &) const;

	operator std::string() const;
	operator double() const;
	operator int() const;
	operator unsigned long() const;

	bool isNull() const { return false; }
	bool isInt() const { return false; }
	bool isUnsignedLongInt() const { return false; }
	bool isDouble() const { return true; }
	bool isString() const { return false; }
};

#endif
