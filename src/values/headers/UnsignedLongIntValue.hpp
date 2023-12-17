#ifndef UNSIGNED_LONG_INT_VALUE_HPP
#define UNSIGNED_LONG_INT_VALUE_HPP

#include "IValue.hpp"

class UnsignedLongIntValue : public IValue {
private:
	unsigned long _value;

public:
	UnsignedLongIntValue(unsigned long);
	UnsignedLongIntValue(UnsignedLongIntValue const &);
	UnsignedLongIntValue & operator=(UnsignedLongIntValue const &);
	~UnsignedLongIntValue();

	void swap(UnsignedLongIntValue &);

	UnsignedLongIntValue * getClone() const override;

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isUnsignedLongInt() const override { return true; }
};

#endif
