#include <algorithm>
#include <string.h>

#include "StringValue.hpp"

#include "UnableToTransformException.hpp"
#include "IncompatibleValueTypesException.hpp"

StringValue::StringValue(std::string const & value) : _value(value.size()) { std::copy(value.begin(), value.end(), _value.begin()); }

StringValue::StringValue(char const * value) : _value(strlen(value)) {
	std::size_t len = strlen(value);
	for (std::size_t i = 0; i < len; ++i)
		_value[i] = value[i];
}

StringValue::StringValue(std::vector<CharValue> const & value) : _value(value) {}

StringValue::StringValue(StringValue const & other) : _value(other.size()) { std::copy(other._value.begin(), other._value.end(), _value.begin()); }

StringValue & StringValue::operator=(StringValue const & other) {
	if (this != &other) {
		StringValue tmp(other);
		swap(tmp);
	}
	return *this;
}
StringValue::~StringValue() {}

void StringValue::swap(StringValue & other) { std::swap(_value, other._value); }

// cloning
StringValue * StringValue::getClone() const { return new StringValue(_value); }

// comparison
bool StringValue::operator<(IValue const & other) const {
	if (!other.isString() && !other.isChar())
		throw IncompatibleValueTypesException{getTypeName(), other.getTypeName()};

	std::size_t len = size();
	if (other.isChar())
		return len < 1;
	if (len != other.size())
		return len < other.size();

	for (std::size_t i = 0; i < len; ++i)
		if (_value.at(i) != other.at(i))
			return _value.at(i) < other.at(i);
	return false;
}

// vector methods
CharValue & StringValue::operator[](std::size_t const & index) { return _value[index]; }
CharValue & StringValue::at(std::size_t const & index) { return _value.at(index); }
CharValue const & StringValue::at(std::size_t const & index) const { return _value.at(index); }
CharValue & StringValue::back() { return _value.back(); }
CharValue const & StringValue::back() const { return _value.back(); }

void StringValue::push_back(IValue const & value) {
	auto const line = value.toString();
	for (char const symb : line)
		_value.push_back(symb);
}

void StringValue::pop_back() { _value.pop_back(); }
std::size_t StringValue::size() const { return _value.size(); }
bool StringValue::empty() const { return _value.empty(); }

// transformation
std::string StringValue::toString() const { return std::string{_value.begin(), _value.end()}; }
char StringValue::toChar() const { return _value.at(0); }
double StringValue::toDouble() const { throw UnableToTransformException(getTypeName(), "double", *this); }
int StringValue::toInt() const { throw UnableToTransformException(getTypeName(), "int", *this); }
unsigned long int StringValue::toUnsignedLongInt() const { throw UnableToTransformException(getTypeName(), "unsigned long int", *this); }
