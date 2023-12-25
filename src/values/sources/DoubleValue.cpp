#include <algorithm>

#include "DoubleValue.hpp"

DoubleValue::DoubleValue(double value) : _value(value) {}
DoubleValue::DoubleValue(DoubleValue const & other) : _value(other) {}

DoubleValue & DoubleValue::operator=(DoubleValue const & other) {
	if (this != &other) {
		DoubleValue tmp(other);
		swap(tmp);
	}
	return *this;
}

DoubleValue::~DoubleValue() {}
void DoubleValue::swap(DoubleValue & other) { std::swap(_value, other._value); }

DoubleValue * DoubleValue::getClone() const { return new DoubleValue(_value); }

bool DoubleValue::operator<(AbstractValue const & other) const { return _value < double(other); }

std::string DoubleValue::toString() const { return std::to_string(_value); }
char DoubleValue::toChar() const { return _value; }
double DoubleValue::toDouble() const { return _value; }
int DoubleValue::toInt() const { return _value; }
unsigned long DoubleValue::toUnsignedLongInt() const { return _value; }

// arithmetic operations
DoubleValue * DoubleValue::add(AbstractValue const * other) const { return new DoubleValue(_value + other->toDouble()); }
DoubleValue * DoubleValue::sub(AbstractValue const * other) const { return new DoubleValue(_value - other->toDouble()); }
DoubleValue * DoubleValue::mul(AbstractValue const * other) const { return new DoubleValue(_value * other->toDouble()); }
DoubleValue * DoubleValue::div(AbstractValue const * other) const { return new DoubleValue(_value / other->toDouble()); }
