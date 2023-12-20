#ifndef UNSIGNED_LONG_INT_VALUE_HPP
#define UNSIGNED_LONG_INT_VALUE_HPP

#include "AbstractValue.hpp"

class UnsignedLongIntValue : public AbstractValue {
private:
	unsigned long _value;

public:
	UnsignedLongIntValue(unsigned long);
	UnsignedLongIntValue(UnsignedLongIntValue const &);
	UnsignedLongIntValue & operator=(UnsignedLongIntValue const &);
	~UnsignedLongIntValue();

	void swap(UnsignedLongIntValue &);

	// cloning
	UnsignedLongIntValue * getClone() const override;

	// comparison
	bool operator<(AbstractValue const &) const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isUnsignedLongInt() const override { return true; }
	std::string getTypeName() const override { return "UnsignedLongIntValue"; }

	// arithmetic operations
	UnsignedLongIntValue * add(AbstractValue const * other) const override;
	UnsignedLongIntValue * sub(AbstractValue const * other) const override;
	UnsignedLongIntValue * mul(AbstractValue const * other) const override;
	UnsignedLongIntValue * div(AbstractValue const * other) const override;
};

#endif
