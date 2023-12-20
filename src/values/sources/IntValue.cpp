#include <algorithm>

#include "IntValue.hpp"

IntValue::IntValue(int value) : _value(value) {}
IntValue::IntValue(IntValue const & other) : _value(other) {}

IntValue & IntValue::operator=(IntValue const & other) {
	if (this != &other) {
		IntValue tmp(other);
		swap(tmp);
	}
	return *this;
}

IntValue::~IntValue() {}
void IntValue::swap(IntValue & other) { std::swap(_value, other._value); }

IntValue * IntValue::getClone() const { return new IntValue(_value); }

bool IntValue::operator<(IValue const & other) const { return _value < int(other); }

// transformation
std::string IntValue::toString() const { return std::to_string(_value); }
char IntValue::toChar() const { return _value; }
double IntValue::toDouble() const { return _value; }
int IntValue::toInt() const { return _value; }
unsigned long IntValue::toUnsignedLongInt() const { return _value; }

// arithmetic operations
IntValue * IntValue::add(IValue const * other) const { return new IntValue(_value + other->toInt()); }
IntValue * IntValue::sub(IValue const * other) const { return new IntValue(_value - other->toInt()); }
IntValue * IntValue::mul(IValue const * other) const { return new IntValue(_value * other->toInt()); }
IntValue * IntValue::div(IValue const * other) const { return new IntValue(_value / other->toInt()); }
