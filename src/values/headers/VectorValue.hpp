#ifndef VECTOR_VALUE_HPP
#define VECTOR_VALUE_HPP

#include <vector>
#include "IValue.hpp"

class VectorValue : public IValue {
private:
	std::vector<IValue *> _values;

public:
	VectorValue(std::vector<IValue const *> const & values = {});
	VectorValue(std::vector<IValue *> const & values);
	VectorValue(VectorValue const & other);
	VectorValue & operator=(VectorValue const & other);
	~VectorValue() override;

	void swap(VectorValue & other);

	// cloning
	VectorValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// vector methods
	IValue & operator[](std::size_t const & index) override;
	IValue & at(std::size_t const & index) override;
	IValue const & at(std::size_t const & index) const override;
	IValue & back() override;
	IValue const & back() const override;

	void push_back(IValue const & value) override;
	void pop_back() override;
	std::size_t size() const override;
	bool empty() const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isIterable() const override { return true; }
	bool isNull() const override { return empty(); }

	std::string getTypeName() const override;

	// arithmetic operations
	VectorValue * add(IValue const * other) const override;
	VectorValue * mul(IValue const * other) const override;
};

#endif
