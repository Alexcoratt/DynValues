#ifndef STRING_VALUE_HPP
#define STRING_VALUE_HPP

#include <vector>

#include "IValue.hpp"
#include "CharValue.hpp"

class StringValue : public IValue {
private:
	std::vector<CharValue> _value;

public:
	StringValue(std::string const &);
	StringValue(char const *);
	StringValue(std::vector<CharValue> const &);
	StringValue(StringValue const &);
	StringValue & operator=(StringValue const &);
	~StringValue();

	void swap(StringValue &);

	// cloning
	StringValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// vector methods
	CharValue & operator[](std::size_t const & index) override;
	CharValue & at(std::size_t const & index) override;
	CharValue const & at(std::size_t const & index) const override;
	CharValue & back() override;
	CharValue const & back() const override;

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
	bool isString() const override { return true; }
	bool isIterable() const override { return true; }
	std::string getTypeName() const override { return "StringValue"; }
};

#endif
