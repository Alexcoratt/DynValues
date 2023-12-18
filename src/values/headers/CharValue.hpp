#ifndef CHAR_VALUE_HPP
#define CHAR_VALUE_HPP

#include "IValue.hpp"

class CharValue : public IValue {
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
	bool operator<(IValue const &) const override;

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
};

#endif
