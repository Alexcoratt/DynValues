#ifndef DOUBLE_VALUE_HPP
#define DOUBLE_VALUE_HPP

#include "AbstractValue.hpp"

class DoubleValue : public AbstractValue {
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
	bool operator<(AbstractValue const &) const override;

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
	DoubleValue * add(AbstractValue const * other) const override;
	DoubleValue * sub(AbstractValue const * other) const override;
	DoubleValue * mul(AbstractValue const * other) const override;
	DoubleValue * div(AbstractValue const * other) const override;
};

#endif
