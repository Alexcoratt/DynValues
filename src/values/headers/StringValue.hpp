#ifndef STRING_VALUE_HPP
#define STRING_VALUE_HPP

#include "IValue.hpp"

class StringValue : public IValue {
private:
	std::string _value;

public:
	StringValue(std::string const &);
	StringValue(char const *);
	StringValue(IValue const &);
	StringValue & operator=(IValue const &);
	~StringValue();

	void swap(StringValue &);

	StringValue * getClone() const;

	bool operator<(IValue const &) const;

	operator std::string() const;
	operator double() const;
	operator int() const;
	operator unsigned long() const;

	bool isNull() const { return false; }
	bool isInt() const { return false; }
	bool isUnsignedLongInt() const { return false; }
	bool isDouble() const { return false; }
	bool isString() const { return true; }
};

#endif
