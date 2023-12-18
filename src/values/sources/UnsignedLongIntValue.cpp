#include "UnsignedLongIntValue.hpp"

UnsignedLongIntValue::UnsignedLongIntValue(unsigned long value) : _value(value) {}
UnsignedLongIntValue::UnsignedLongIntValue(UnsignedLongIntValue const & other) : _value(other._value) {}

UnsignedLongIntValue & UnsignedLongIntValue::operator=(UnsignedLongIntValue const & other) {
	_value = other;
	return *this;
}

UnsignedLongIntValue::~UnsignedLongIntValue() {}

// cloning
UnsignedLongIntValue * UnsignedLongIntValue::getClone() const { return new UnsignedLongIntValue(_value); }

// comparison
bool UnsignedLongIntValue::operator<(IValue const & other) const { return _value < (unsigned long)other; }

// vector methods are unappliable

// typechecking
std::string UnsignedLongIntValue::toString() const { return std::to_string(_value); }
char UnsignedLongIntValue::toChar() const { return _value; }
double UnsignedLongIntValue::toDouble() const { return _value; }
int UnsignedLongIntValue::toInt() const { return _value; }
unsigned long int UnsignedLongIntValue::toUnsignedLongInt() const { return _value; }
