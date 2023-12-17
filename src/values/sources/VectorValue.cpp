#include <algorithm>
#include <sstream>

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

VectorValue * VectorValue::getClone() const {
	std::size_t len = _values.size();
	std::vector<IValue const *> res{len};
	for (std::size_t i = 0; i < len; ++i)
		res[i] = _values.at(i)->getClone();
	return new VectorValue{res};
}

bool VectorValue::operator<(IValue const & other) const {
	auto otherVector = dynamic_cast<VectorValue const *>(&other);
	if (!otherVector)
		throw IncompatibleValueTypesException("VectorValue", "not a VectorValue");
	std::size_t len = _values.size();
	std::size_t otherLen = otherVector->_values.size();
	if (len != otherLen)
		return len < otherLen;
	for (std::size_t i = 0; i < len; ++i)
		if (_values.at(i) != otherVector->at(i))
			return _values.at(i) < otherVector->at(i);
	return false;
}

VectorValue::operator std::string() const {
	std::stringstream str;
	str << '[';
	std::size_t len = _values.size();
	if (len != 0)
		str << (std::string)*_values[0];
	for (std::size_t i = 1; i < len; ++i)
		str << ", " << (std::string)*_values[i];
	str << ']';
	return str.str();
}

VectorValue::operator double() const { throw UnableToTransformException("VectorValue", "DoubleValue"); }
VectorValue::operator int() const { throw UnableToTransformException("VectorValue", "IntValue"); }
VectorValue::operator unsigned long() const { throw UnableToTransformException("VectorValue", "UnsignedLongValue"); }

IValue * VectorValue::operator[](std::size_t const & index) { return _values[index]; }
IValue * VectorValue::at(std::size_t const & index) { return _values.at(index); }
IValue const * VectorValue::at(std::size_t const & index) const { return _values.at(index); }
IValue * VectorValue::back() { return _values.back(); }
IValue const * VectorValue::back() const { return _values.back(); }

void VectorValue::push_back(IValue const * value) { _values.push_back(value->getClone()); }
void VectorValue::pop_back() {
	IValue * value = _values.back();
	_values.pop_back();
	delete value;
}

std::size_t VectorValue::size() const { return _values.size(); }

bool VectorValue::empty() const { return _values.empty(); }
