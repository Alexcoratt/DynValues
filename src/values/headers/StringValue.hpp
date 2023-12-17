#ifndef STRING_VALUE_HPP
#define STRING_VALUE_HPP

#include "IValue.hpp"

class StringValue : public IValue {
private:
	std::string _value;

public:
	StringValue(std::string const &);
	StringValue(char const *);
	StringValue(StringValue const &);
	StringValue & operator=(StringValue const &);
	~StringValue();

	void swap(StringValue &);

	StringValue * getClone() const override;

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isString() const override { return true; }
};

#endif
