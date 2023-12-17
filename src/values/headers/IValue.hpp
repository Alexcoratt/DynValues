#ifndef I_VALUE_HPP
#define I_VALUE_HPP

#include <string>
#include <vector>
#include <map>

class IValue {
public:
	virtual ~IValue() {}
	virtual IValue * getClone() const = 0;	// returns pointer to the heap located object

	virtual bool operator<(IValue const &) const = 0;
	virtual bool operator>(IValue const & other) const { return other < *this; }
	virtual bool operator==(IValue const & other) const { return !(*this < other || *this > other); }
	virtual bool operator!=(IValue const & other) const { return !(*this == other); }
	virtual bool operator>=(IValue const & other) const { return !(*this < other); }
	virtual bool operator<=(IValue const & other) const { return !(*this > other); }

	virtual operator std::string() const = 0;
	virtual operator double() const = 0;
	virtual operator int() const = 0;
	virtual operator unsigned long() const = 0;

	virtual bool isNull() const { return false; }
	virtual bool isInt() const { return false; }
	virtual bool isUnsignedLongInt() const { return false; }
	virtual bool isDouble() const { return false; }
	virtual bool isString() const { return false; }
	virtual bool isVector() const { return false; }
};

inline std::ostream & operator<<(std::ostream & stream, IValue const & value) {
	stream << std::string(value);
	return stream;
}

#endif
