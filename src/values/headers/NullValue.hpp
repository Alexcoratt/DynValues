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

	// vector methods
	IValue & operator[](std::size_t const & index) override { return *this; }
	IValue & at(std::size_t const & index) override { return *this; }
	IValue const & at(std::size_t const & index) const override { return *this; }
	IValue & back() override { return *this; }
	IValue const & back() const override { return *this; }

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
	IValue * add(IValue const * other) const override;
	IValue * sub(IValue const * other) const override;
	IValue * mul(IValue const * other) const override;
	IValue * div(IValue const * other) const override;
};

#endif
