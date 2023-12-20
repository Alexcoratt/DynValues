#include "NullValue.hpp"

NullValue * NullValue::getClone() const { return new NullValue; }

NullValue & NullValue::operator=(NullValue const &) { return *this; }

bool NullValue::operator<(IValue const & other) const {
	if (other.isNull())
		return false;
	return true;
}

std::string NullValue::toString() const { return ""; }
char NullValue::toChar() const { return '\0'; }
double NullValue::toDouble() const { return 0; }
int NullValue::toInt() const { return 0; }
unsigned long NullValue::toUnsignedLongInt() const { return 0; }

// arithmetic operations
IValue * NullValue::add(IValue const * other) const { return other->add(this); }
IValue * NullValue::sub(IValue const * other) const { return other->sub(this); }
IValue * NullValue::mul(IValue const * other) const { return other->mul(this); }
IValue * NullValue::div(IValue const * other) const { return other->div(this); }
