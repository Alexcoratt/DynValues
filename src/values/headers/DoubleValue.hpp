#ifndef DOUBLE_VALUE_HPP
#define DOUBLE_VALUE_HPP

#include "IValue.hpp"

class DoubleValue : public IValue {
private:
	double _value;

public:
	DoubleValue(double);
	DoubleValue(DoubleValue const &);
	DoubleValue & operator=(DoubleValue const &);
	~DoubleValue();

	void swap(DoubleValue &);

	// cloning
	DoubleValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isDouble() const override { return true; }
	std::string getTypeName() const override { return "DoubleValue"; }

	// arithmetic operations
	DoubleValue * add(IValue const * other) const override;
	DoubleValue * sub(IValue const * other) const override;
	DoubleValue * mul(IValue const * other) const override;
	DoubleValue * div(IValue const * other) const override;
};

#endif
