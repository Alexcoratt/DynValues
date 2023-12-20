#ifndef INT_VALUE_HPP
#define INT_VALUE_HPP

#include "IValue.hpp"

class IntValue : public IValue {
private:
	int _value;

public:
	IntValue(int);
	IntValue(IntValue const &);
	IntValue & operator=(IntValue const &);
	~IntValue();

	void swap(IntValue &);

	// cloning
	IntValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isInt() const override { return true; }
	std::string getTypeName() const override { return "IntValue"; }

	// arithmetic operations
	IntValue * add(IValue const * other) const override;
	IntValue * sub(IValue const * other) const override;
	IntValue * mul(IValue const * other) const override;
	IntValue * div(IValue const * other) const override;
};

#endif
