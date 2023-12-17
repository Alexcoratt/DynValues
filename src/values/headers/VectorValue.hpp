#ifndef VECTOR_VALUE_HPP
#define VECTOR_VALUE_HPP

#include <vector>
#include "IValue.hpp"

class VectorValue : public IValue {
private:
	std::vector<IValue *> _values;

public:
	VectorValue(std::vector<IValue const *> const & values = {});
	VectorValue(VectorValue const & other);
	VectorValue & operator=(VectorValue const & other);
	~VectorValue() override;

	void swap(VectorValue & other);

	VectorValue * getClone() const override;

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	IValue * operator[](std::size_t const & index);
	IValue * at(std::size_t const & index);
	IValue const * at(std::size_t const & index) const;
	IValue * back();
	IValue const * back() const;

	void push_back(IValue const * value);
	void pop_back();
	std::size_t size() const;
	bool empty() const;

	bool isVector() const override { return true; }
};

#endif
