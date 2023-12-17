#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "AutoValue.hpp"
#include "DoubleValue.hpp"
#include "IntValue.hpp"
#include "UnsignedLongIntValue.hpp"
#include "StringValue.hpp"
#include "NullValue.hpp"

AutoValue::AutoValue() : _value(new NullValue) {}
AutoValue::AutoValue(AutoValue const & other) : _value(other._value->getClone()) {}
AutoValue::AutoValue(IValue const & value) : _value(value.getClone()) {}
AutoValue::AutoValue(IValue const * value) : _value(value->getClone()) {}
AutoValue::AutoValue(double value) : _value(new DoubleValue(value)) {}
AutoValue::AutoValue(int value) : _value(new IntValue(value)) {}
AutoValue::AutoValue(unsigned long value) : _value(new UnsignedLongIntValue(value)) {}
AutoValue::AutoValue(std::string const & value) : _value(new StringValue(value)) {}
AutoValue::AutoValue(char const * value) : _value(new StringValue(value)) {}

AutoValue::AutoValue(std::vector<IValue const *> const & values) : _value(new VectorValue{values}) {}

AutoValue & AutoValue::operator=(AutoValue const & other) {
	if (this != &other) {
		AutoValue tmp(other);
		swap(tmp);
	}
	return *this;
}

AutoValue::~AutoValue() {}

int AutoValue::nestCount() const {
	AutoValue const * value = dynamic_cast<AutoValue const *>(_value.get());
	if (value)
		return 1 + value->nestCount();
	return 0;
}

void AutoValue::clear() { _value.reset(new NullValue()); }

void AutoValue::swap(AutoValue & other) { std::swap(_value, other._value); }

AutoValue * AutoValue::getClone() const {
	return new AutoValue(_value.get());
}
bool AutoValue::operator<(IValue const & other) const { return *_value < other; }

// vector methods
IValue & AutoValue::operator[](std::size_t const & index) {
	if (index == 0)
		return *_value;
	if (isVector())
		return *(*(VectorValue *)_value.get())[index];
	throw std::out_of_range("Index " + std::to_string(index) + " is out of range 1");
}

IValue & AutoValue::at(std::size_t const & index) {
	if (index == 0)
		return *_value;
	if (isVector())
		return *((VectorValue *)_value.get())->at(index);
	throw std::out_of_range("Index " + std::to_string(index) + " is out of range 1");
}

IValue const & AutoValue::at(std::size_t const & index) const {
	if (index == 0)
		return *_value;
	if (isVector())
		return *((VectorValue *)_value.get())->at(index);
	throw std::out_of_range("Index " + std::to_string(index) + " is out of range 1");
}

IValue & AutoValue::back() {
	if (isVector())
		return *((VectorValue *)_value.get())->back();
	return *_value;
}

IValue const & AutoValue::back() const {
	if (isVector())
		return *((VectorValue *)_value.get())->back();
	return *_value;
}

void AutoValue::push_back(IValue const & value) {
	if (isVector()) {
		((VectorValue *)_value.get())->push_back(&value);
		return;
	}
	_value.reset(new VectorValue{{_value.get(), &value}});
}

void AutoValue::pop_back() {
	if (isVector()) {
		((VectorValue *)_value.get())->pop_back();
		return;
	}
	_value.reset(new VectorValue{});
}

std::size_t AutoValue::size() const {
	if (isVector())
		return ((VectorValue *)_value.get())->size();
	if (isNull())
		return 0;
	return 1;
}

bool AutoValue::empty() const {
	if (isVector())
		return ((VectorValue *)_value.get())->empty();
	if (isNull())
		return true;
	return false;
}

// type transformation methods
AutoValue::operator std::string() const { return *_value; }
AutoValue::operator double() const { return *_value; }
AutoValue::operator int() const { return *_value; }
AutoValue::operator unsigned long() const { return *_value; }

bool AutoValue::isNull() const { return _value->isNull(); }
bool AutoValue::isInt() const { return _value->isInt(); }
bool AutoValue::isUnsignedLongInt() const { return _value->isUnsignedLongInt(); }
bool AutoValue::isDouble() const { return _value->isDouble(); }
bool AutoValue::isString() const { return _value->isString(); }
bool AutoValue::isVector() const { return _value->isVector(); }
