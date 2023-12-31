#include <algorithm>
#include <sstream>
#include <iostream>

#include "VectorValue.hpp"
#include "UnableToTransformException.hpp"
#include "IncompatibleValueTypesException.hpp"

VectorValue::VectorValue(std::vector<AbstractValue const *> const & values) : _values{values.size()} {
	std::size_t len = _values.size();
	for (std::size_t i = 0; i < len; ++i)
		_values[i] = values.at(i)->getClone();
}

VectorValue::VectorValue(std::vector<AbstractValue *> const & values) : _values{values.size()} {
	std::size_t len = _values.size();
	for (std::size_t i = 0; i < len; ++i)
		_values[i] = values.at(i)->getClone();
}

VectorValue::VectorValue(VectorValue const & other) : _values{other._values.size()} {
	std::size_t len = _values.size();
	for (std::size_t i = 0; i < len; ++i)
		_values[i] = other._values.at(i)->getClone();
}

VectorValue & VectorValue::operator=(VectorValue const & other) {
	if (this != &other) {
		VectorValue tmp{other};
		swap(tmp);
	}
	return *this;
}

VectorValue::~VectorValue() {
	for (auto value : _values)
		delete value;
}

void VectorValue::swap(VectorValue & other) {
	std::swap(_values, other._values);
}

// cloning
VectorValue * VectorValue::getClone() const {
	std::size_t len = _values.size();
	std::vector<AbstractValue *> values{len};
	for (std::size_t i = 0; i < len; ++i)
		values[i] = _values.at(i)->getClone();
	VectorValue * res = new VectorValue;
	res->_values = values;
	return res;
}

// comparison
bool VectorValue::operator<(AbstractValue const & other) const {
	if (!other.isIterable())
		throw IncompatibleValueTypesException(getTypeName(), other.getTypeName());
	std::size_t len = _values.size();
	if (len != other.size())
		return len < other.size();
	for (std::size_t i = 0; i < len; ++i)
		if (at(i) != other.at(i))
			return at(i) < other.at(i);
	return false;
}

// vector methods
AbstractValue & VectorValue::operator[](std::size_t const & index) { return *_values[index]; }
AbstractValue & VectorValue::at(std::size_t const & index) { return *_values.at(index); }
AbstractValue const & VectorValue::at(std::size_t const & index) const { return *_values.at(index); }
AbstractValue & VectorValue::back() { return *_values.back(); }
AbstractValue const & VectorValue::back() const { return *_values.back(); }

void VectorValue::push_back(AbstractValue const & value) {
	_values.push_back(value.getClone());
}
void VectorValue::pop_back() {
	AbstractValue * value = _values.back();
	_values.pop_back();
	delete value;
}

std::size_t VectorValue::size() const { return _values.size(); }
bool VectorValue::empty() const { return _values.empty(); }

// transformation
std::string VectorValue::toString() const {
	std::stringstream str;
	str << '[';
	std::size_t len = _values.size();
	if (len != 0)
		str << _values[0]->toString();
	for (std::size_t i = 1; i < len; ++i)
		str << ", " << _values[i]->toString();
	str << ']';
	return str.str();
}

char VectorValue::toChar() const { throw UnableToTransformException(getTypeName(), "char"); }
double VectorValue::toDouble() const { throw UnableToTransformException(getTypeName(), "double"); }
int VectorValue::toInt() const { throw UnableToTransformException(getTypeName(), "int"); }
unsigned long int VectorValue::toUnsignedLongInt() const { throw UnableToTransformException(getTypeName(), "unsigned long int"); }

// typechecking
std::string VectorValue::getTypeName() const {
	/*
	std::stringstream str;
	str << "VectorValue [";
	std::size_t len = _values.size();
	if (len != 0)
		str << _values[0]->getTypeName();
	for (std::size_t i = 1; i < len; ++i)
		str << ", " << _values[i]->getTypeName();
	str << ']';
	return str.str();
	*/
	return "VectorValue";
}

// arithmetic operations
VectorValue * VectorValue::add(AbstractValue const * other) const {
	auto otherSize = other->size();
	VectorValue * res = new VectorValue(_values);
	for (std::size_t i = 0; i < otherSize; ++i)
		res->push_back(other->at(i));
	return res;
}
VectorValue * VectorValue::mul(AbstractValue const * other) const {
	auto count = other->toUnsignedLongInt();
	VectorValue * res = new VectorValue;
	auto const len = _values.size();
	while (count--) {
		for (std::size_t i = 0; i < len; ++i)
			res->push_back(*_values.at(i));
	}
	return res;
}
