#ifndef UNSIGNED_LONG_INT_VALUE_HPP
#define UNSIGNED_LONG_INT_VALUE_HPP

#include "IValue.hpp"

class UnsignedLongIntValue : public IValue {
private:
	unsigned long _value;

public:
	UnsignedLongIntValue(unsigned long);
	UnsignedLongIntValue(UnsignedLongIntValue const &);
	UnsignedLongIntValue & operator=(IValue const &);
	~UnsignedLongIntValue();

	void swap(UnsignedLongIntValue &);

	UnsignedLongIntValue * getClone() const;

	bool operator<(IValue const &) const;

	operator std::string() const;
	operator double() const;
	operator int() const;
	operator unsigned long() const;

	bool isNull() const { return false; }
	bool isInt() const { return false; }
	bool isUnsignedLongInt() const { return true; }
	bool isDouble() const { return false; }
	bool isString() const { return false; }
};

#endif
