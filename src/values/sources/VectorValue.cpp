#include <algorithm>
#include <sstream>
#include <iostream>

#include "VectorValue.hpp"
#include "UnableToTransformException.hpp"
#include "IncompatibleValueTypesException.hpp"

VectorValue::VectorValue(std::vector<IValue const *> const & values) : _values{values.size()} {
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
	std::vector<IValue *> values{len};
	for (std::size_t i = 0; i < len; ++i)
		values[i] = _values.at(i)->getClone();
	VectorValue * res = new VectorValue;
	res->_values = values;
	return res;
}

// comparison
bool VectorValue::operator<(IValue const & other) const {
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
IValue & VectorValue::operator[](std::size_t const & index) { return *_values[index]; }
IValue & VectorValue::at(std::size_t const & index) { return *_values.at(index); }
IValue const & VectorValue::at(std::size_t const & index) const { return *_values.at(index); }
IValue & VectorValue::back() { return *_values.back(); }
IValue const & VectorValue::back() const { return *_values.back(); }

void VectorValue::push_back(IValue const & value) {
	_values.push_back(value.getClone());
}
void VectorValue::pop_back() {
	IValue * value = _values.back();
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
	std::stringstream str;
	str << "VectorValue [";
	std::size_t len = _values.size();
	if (len != 0)
		str << _values[0]->getTypeName();
	for (std::size_t i = 1; i < len; ++i)
		str << ", " << _values[i]->getTypeName();
	str << ']';
	return str.str();
}
