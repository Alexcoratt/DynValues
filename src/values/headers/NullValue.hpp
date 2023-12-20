#ifndef NULL_VALUE_HPP
#define NULL_VALUE_HPP

#include "AbstractValue.hpp"

class NullValue : public AbstractValue {
public:
	NullValue & operator=(NullValue const &);

	// cloning
	NullValue * getClone() const override;

	// comparison
	bool operator<(AbstractValue const &) const override;

	// vector methods
	AbstractValue & operator[](std::size_t const & index) override { return *this; }
	AbstractValue & at(std::size_t const & index) override { return *this; }
	AbstractValue const & at(std::size_t const & index) const override { return *this; }
	AbstractValue & back() override { return *this; }
	AbstractValue const & back() const override { return *this; }

	std::size_t size() const override { return 0; }
	bool empty() const override { return true; }

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isNull() const override { return true; }
	std::string getTypeName() const override { return "NullValue"; }

	// arithmetic operations
	AbstractValue * add(AbstractValue const * other) const override;
	AbstractValue * sub(AbstractValue const * other) const override;
	AbstractValue * mul(AbstractValue const * other) const override;
	AbstractValue * div(AbstractValue const * other) const override;
};

#endif
