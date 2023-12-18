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

	// cloning
	UnsignedLongIntValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isUnsignedLongInt() const override { return true; }
	std::string getTypeName() const override { return "UnsignedLongIntValue"; }
};

#endif
