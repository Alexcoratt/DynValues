#ifndef VECTOR_VALUE_HPP
#define VECTOR_VALUE_HPP

#include <vector>
#include "AbstractValue.hpp"

class VectorValue : public AbstractValue {
private:
	std::vector<AbstractValue *> _values;

public:
	VectorValue(std::vector<AbstractValue const *> const & values = {});
	VectorValue(std::vector<AbstractValue *> const & values);
	VectorValue(VectorValue const & other);
	VectorValue & operator=(VectorValue const & other);
	~VectorValue() override;

	void swap(VectorValue & other);

	// cloning
	VectorValue * getClone() const override;

	// comparison
	bool operator<(AbstractValue const &) const override;

	// vector methods
	AbstractValue & operator[](std::size_t const & index) override;
	AbstractValue & at(std::size_t const & index) override;
	AbstractValue const & at(std::size_t const & index) const override;
	AbstractValue & back() override;
	AbstractValue const & back() const override;

	void push_back(AbstractValue const & value) override;
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
	VectorValue * add(AbstractValue const * other) const override;
	VectorValue * mul(AbstractValue const * other) const override;
};

#endif
