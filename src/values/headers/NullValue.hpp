#ifndef NULL_VALUE_HPP
#define NULL_VALUE_HPP

#include "IValue.hpp"

class NullValue : public IValue {
public:
	NullValue & operator=(NullValue const &);

	// cloning
	NullValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isNull() const override { return true; }
	std::string getTypeName() const override { return "NullValue"; }
};

#endif
