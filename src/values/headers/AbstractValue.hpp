#ifndef ABSTRACT_VALUE_HPP
#define ABSTRACT_VALUE_HPP

#include <string>
#include <vector>
#include <map>

#include "NonIterableValueTypeException.hpp"
#include "WrongArithmeticOperationException.hpp"

class AbstractValue {
public:
	virtual ~AbstractValue() {}

	// cloning
	virtual AbstractValue * getClone() const = 0;	// returns pointer to the heap located object

	// comparison
	virtual bool operator<(AbstractValue const &) const = 0;
	virtual bool operator>(AbstractValue const & other) const { return other < *this; }
	virtual bool operator==(AbstractValue const & other) const { return !(*this < other || *this > other); }
	virtual bool operator!=(AbstractValue const & other) const { return !(*this == other); }
	virtual bool operator>=(AbstractValue const & other) const { return !(*this < other); }
	virtual bool operator<=(AbstractValue const & other) const { return !(*this > other); }

	// vector methods
	virtual AbstractValue & operator[](std::size_t const & index) {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual AbstractValue & at(std::size_t const & index) {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual AbstractValue const & at(std::size_t const & index) const {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual AbstractValue & back() {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual AbstractValue const & back() const {
		throw NonIterableValueTypeException{getTypeName()};
	}

	virtual void push_back(AbstractValue const & value) {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual void pop_back() {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual std::size_t size() const {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual bool empty() const {
		throw NonIterableValueTypeException{getTypeName()};
	}

	// transformation
	virtual std::string toString() const = 0;
	virtual operator std::string() const { return toString(); };

	virtual char toChar() const = 0;
	virtual operator char() const { return toChar(); }

	virtual double toDouble() const = 0;
	virtual operator double() const { return toDouble(); };

	virtual int toInt() const = 0;
	virtual operator int() const { return toDouble(); };

	virtual unsigned long toUnsignedLongInt() const = 0;
	virtual operator unsigned long() const { return toUnsignedLongInt(); };

	// typechecking
	virtual bool isNull() const { return false; }
	virtual bool isInt() const { return false; }
	virtual bool isUnsignedLongInt() const { return false; }
	virtual bool isDouble() const { return false; }
	virtual bool isString() const { return false; }
	virtual bool isChar() const { return false; }
	virtual bool isIterable() const { return false; }
	virtual bool isDate() const { return false; }

	virtual std::string getTypeName() const = 0;

	// arithmetic operations
	virtual AbstractValue * add(AbstractValue const * other) const { throw WrongArithmeticOperationException{getTypeName(), "addition"}; }
	virtual AbstractValue * sub(AbstractValue const * other) const { throw WrongArithmeticOperationException{getTypeName(), "subtraction"}; }
	virtual AbstractValue * mul(AbstractValue const * other) const { throw WrongArithmeticOperationException{getTypeName(), "multiplication"}; }
	virtual AbstractValue * div(AbstractValue const * other) const { throw WrongArithmeticOperationException{getTypeName(), "division"}; }
};

inline std::ostream & operator<<(std::ostream & stream, AbstractValue const & value) {
	stream << std::string(value);
	return stream;
}

#endif
