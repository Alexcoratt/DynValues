#ifndef CHAR_VALUE_HPP
#define CHAR_VALUE_HPP

#include "AbstractValue.hpp"

class CharValue : public AbstractValue {
private:
	char _value;

public:
	CharValue(char value = '\0');
	CharValue(CharValue const & other);
	CharValue & operator=(CharValue const & other);
	~CharValue();

	void swap(CharValue & other);

	// cloning
	CharValue * getClone() const override;

	// comparison
	bool operator<(AbstractValue const &) const override;

	// vector methods are unappliable

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isChar() const override { return true; }
	std::string getTypeName() const override { return "CharValue"; }

	// arithmetic operations
	CharValue * add(AbstractValue const * other) const override;
	CharValue * sub(AbstractValue const * other) const override;
	CharValue * mul(AbstractValue const * other) const override;
	CharValue * div(AbstractValue const * other) const override;
};

#endif
