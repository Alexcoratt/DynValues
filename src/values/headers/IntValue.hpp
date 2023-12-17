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

	IntValue * getClone() const override;

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isInt() const override { return true; }
};

#endif
