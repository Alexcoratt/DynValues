#include <algorithm>

#include "StringValue.hpp"
#include "UnableToTransformException.hpp"

StringValue::StringValue(std::string const & value) : _value(value) {}
StringValue::StringValue(char const * value) : _value(value) {}
StringValue::StringValue(StringValue const & other) : _value(other) {}
StringValue & StringValue::operator=(StringValue const & other) {
	if (this != &other) {
		StringValue tmp(other);
		swap(tmp);
	}
	return *this;
}
StringValue::~StringValue() {}

void StringValue::swap(StringValue & other) { std::swap(_value, other._value); }

StringValue * StringValue::getClone() const { return new StringValue(_value); }

bool StringValue::operator<(IValue const & other) const { return _value < std::string(other); }

StringValue::operator std::string() const { return _value; }

StringValue::operator double() const {
	throw UnableToTransformException("StringValue", "DoubleValue", _value);
}

StringValue::operator int() const {
	throw UnableToTransformException("StringValue", "IntValue", _value);
}

StringValue::operator unsigned long() const {
	throw UnableToTransformException("StringValue", "UnsignedLongValue", _value);
}
