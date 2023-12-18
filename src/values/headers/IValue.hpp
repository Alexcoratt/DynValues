#ifndef I_VALUE_HPP
#define I_VALUE_HPP

#include <string>
#include <vector>
#include <map>

#include "NonIterableValueTypeException.hpp"

class IValue {
public:
	virtual ~IValue() {}

	// cloning
	virtual IValue * getClone() const = 0;	// returns pointer to the heap located object

	// comparison
	virtual bool operator<(IValue const &) const = 0;
	virtual bool operator>(IValue const & other) const { return other < *this; }
	virtual bool operator==(IValue const & other) const { return !(*this < other || *this > other); }
	virtual bool operator!=(IValue const & other) const { return !(*this == other); }
	virtual bool operator>=(IValue const & other) const { return !(*this < other); }
	virtual bool operator<=(IValue const & other) const { return !(*this > other); }

	// vector methods
	virtual IValue & operator[](std::size_t const & index) {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual IValue & at(std::size_t const & index) {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual IValue const & at(std::size_t const & index) const {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual IValue & back() {
		throw NonIterableValueTypeException{getTypeName()};
	}
	virtual IValue const & back() const {
		throw NonIterableValueTypeException{getTypeName()};
	}

	virtual void push_back(IValue const & value) {
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

	virtual std::string getTypeName() const = 0;
};

inline std::ostream & operator<<(std::ostream & stream, IValue const & value) {
	stream << std::string(value);
	return stream;
}

#endif
