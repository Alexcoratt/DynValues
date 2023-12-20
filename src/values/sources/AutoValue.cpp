#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "AutoValue.hpp"
#include "DoubleValue.hpp"
#include "IntValue.hpp"
#include "UnsignedLongIntValue.hpp"
#include "StringValue.hpp"
#include "NullValue.hpp"
#include "VectorValue.hpp"

AutoValue::AutoValue() : _value(new NullValue) {}
AutoValue::AutoValue(AutoValue const & other) : _value(other._value->getClone()) {}
AutoValue::AutoValue(AbstractValue const & value) {
	auto autoValue = dynamic_cast<AutoValue const *>(&value);
	if (autoValue)
		_value.reset(autoValue->_value->getClone());
	else
		_value.reset(value.getClone());
}
AutoValue::AutoValue(AbstractValue const * value) {
	auto autoValue = dynamic_cast<AutoValue const *>(value);
	if (autoValue)
		_value.reset(autoValue->_value->getClone());
	else
		_value.reset(value->getClone());
}
AutoValue::AutoValue(double value) : _value(new DoubleValue(value)) {}
AutoValue::AutoValue(int value) : _value(new IntValue(value)) {}
AutoValue::AutoValue(unsigned long value) : _value(new UnsignedLongIntValue(value)) {}
AutoValue::AutoValue(std::string const & value) : _value(new StringValue(value)) {}
AutoValue::AutoValue(char const * value) : _value(new StringValue(value)) {}

AutoValue::AutoValue(std::vector<AbstractValue const *> const & values) : _value(new VectorValue{values}) {}

AutoValue & AutoValue::operator=(AutoValue const & other) {
	if (this != &other) {
		AutoValue tmp(other);
		swap(tmp);
	}
	return *this;
}

AutoValue::~AutoValue() {}

void AutoValue::clear() { _value.reset(new NullValue()); }

void AutoValue::swap(AutoValue & other) { std::swap(_value, other._value); }

// clonning
AutoValue * AutoValue::getClone() const {
	return new AutoValue(_value.get());
}

// comparison
bool AutoValue::operator<(AbstractValue const & other) const { return *_value < other; }

// vector methods
AbstractValue & AutoValue::operator[](std::size_t const & index) {
	if (isIterable())
		return (*_value)[index];
	if (index == 0)
		return *_value;
	throw std::out_of_range("Index " + std::to_string(index) + " is out of range 1");
}

AbstractValue & AutoValue::at(std::size_t const & index) {
	if (isIterable())
		return _value->at(index);
	if (index == 0)
		return *_value;
	throw std::out_of_range("Index " + std::to_string(index) + " is out of range 1");
}

AbstractValue const & AutoValue::at(std::size_t const & index) const {
	if (isIterable())
		return _value->at(index);
	if (index == 0)
		return *_value;
	throw std::out_of_range("Index " + std::to_string(index) + " is out of range 1");
}

AbstractValue & AutoValue::back() {
	if (isIterable())
		return _value->back();
	return *_value;
}

AbstractValue const & AutoValue::back() const {
	if (isIterable())
		return _value->back();
	return *_value;
}

void AutoValue::push_back(AbstractValue const & value) {
	if (isIterable()) {
		_value->push_back(value);
		return;
	}
	if (isNull()) {
		_value.reset(value.getClone());
		return;
	}
	_value.reset(new VectorValue{{_value.get(), &value}});
}

void AutoValue::pop_back() {
	if (isIterable()) {
		_value->pop_back();
		return;
	}
	_value.reset(new VectorValue{});
}

std::size_t AutoValue::size() const {
	if (isIterable())
		return _value->size();
	if (isNull())
		return 0;
	return 1;
}

bool AutoValue::empty() const {
	if (isIterable())
		return _value->empty();
	if (isNull())
		return true;
	return false;
}

// type transformation methods
std::string AutoValue::toString() const { return _value->toString(); }
char AutoValue::toChar() const { return _value->toChar(); }
double AutoValue::toDouble() const { return _value->toDouble(); }
int AutoValue::toInt() const { return _value->toInt(); }
unsigned long int AutoValue::toUnsignedLongInt() const { return _value->toUnsignedLongInt(); }

// typechecking
bool AutoValue::isNull() const { return _value->isNull(); }
bool AutoValue::isInt() const { return _value->isInt(); }
bool AutoValue::isUnsignedLongInt() const { return _value->isUnsignedLongInt(); }
bool AutoValue::isDouble() const { return _value->isDouble(); }
bool AutoValue::isString() const { return _value->isString(); }
bool AutoValue::isChar() const { return _value->isChar(); }
bool AutoValue::isIterable() const { return _value->isIterable(); }

std::string AutoValue::getTypeName() const { return "AutoValue: " + _value->getTypeName(); }

// arithmetic operations
AutoValue * AutoValue::add(AbstractValue const * other) const {
	AutoValue * res = new AutoValue;
	res->_value.reset(_value->add(other));
	return res;
}

AutoValue * AutoValue::sub(AbstractValue const * other) const {
	AutoValue * res = new AutoValue;
	res->_value.reset(_value->sub(other));
	return res;
}

AutoValue * AutoValue::mul(AbstractValue const * other) const {
	AutoValue * res = new AutoValue;
	res->_value.reset(_value->mul(other));
	return res;
}

AutoValue * AutoValue::div(AbstractValue const * other) const {
	AutoValue * res = new AutoValue;
	res->_value.reset(_value->div(other));
	return res;
}

// arithmetic operators
AutoValue AutoValue::operator+(AbstractValue const & other) const {
	AutoValue res;
	res._value.reset(_value->add(&other));
	return res;
}

AutoValue AutoValue::operator-(AbstractValue const & other) const {
	AutoValue res;
	res._value.reset(_value->sub(&other));
	return res;
}

AutoValue AutoValue::operator*(AbstractValue const & other) const {
	AutoValue res;
	res._value.reset(_value->mul(&other));
	return res;
}

AutoValue AutoValue::operator/(AbstractValue const & other) const {
	AutoValue res;
	res._value.reset(_value->div(&other));
	return res;
}
