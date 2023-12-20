#include <algorithm>
#include "CharValue.hpp"

CharValue::CharValue(char value) : _value{value} {}
CharValue::CharValue(CharValue const & other) : _value{other._value} {}

CharValue & CharValue::operator=(CharValue const & other) {
	if (this != &other) {
		CharValue tmp{other};
		swap(tmp);
	}
	return *this;
}

CharValue::~CharValue() {}

void CharValue::swap(CharValue & other) {
	std::swap(_value, other._value);
}

// cloning
CharValue * CharValue::getClone() const { return new CharValue{*this}; }

// comparison
bool CharValue::operator<(AbstractValue const & other) const { return _value < other.toChar(); }

// transformation
std::string CharValue::toString() const { return std::string{_value}; }
char CharValue::toChar() const { return _value; }
double CharValue::toDouble() const { return _value; }
int CharValue::toInt() const { return _value; }
unsigned long CharValue::toUnsignedLongInt() const { return _value; }

// arithmetic operations
CharValue * CharValue::add(AbstractValue const * other) const { return new CharValue(_value + other->toChar()); }
CharValue * CharValue::sub(AbstractValue const * other) const { return new CharValue(_value - other->toChar()); }
CharValue * CharValue::mul(AbstractValue const * other) const { return new CharValue(_value * other->toChar()); }
CharValue * CharValue::div(AbstractValue const * other) const { return new CharValue(_value / other->toChar()); }
