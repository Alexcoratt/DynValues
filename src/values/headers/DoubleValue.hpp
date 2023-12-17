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

	DoubleValue * getClone() const override;

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isDouble() const override { return true; }
};

#endif
