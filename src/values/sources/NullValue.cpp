#include "NullValue.hpp"

NullValue * NullValue::getClone() const { return new NullValue; }

NullValue & NullValue::operator=(NullValue const &) { return *this; }

bool NullValue::operator<(IValue const & other) const {
	if (other.isNull())
		return false;
	return true;
}

std::string NullValue::toString() const { return "null"; }
char NullValue::toChar() const { return '\0'; }
double NullValue::toDouble() const { return 0; }
int NullValue::toInt() const { return 0; }
unsigned long NullValue::toUnsignedLongInt() const { return 0; }
