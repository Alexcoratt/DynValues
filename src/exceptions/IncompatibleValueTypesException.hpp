#ifndef INCOMPATIBLE_VALUE_TYPES_EXCEPTION_HPP
#define INCOMPATIBLE_VALUE_TYPES_EXCEPTION_HPP

#include <exception>
#include <stdexcept>
#include <vector>
#include <string>

class IncompatibleValueTypesException : public std::exception {
private:
	std::string _msg;

public:
	inline IncompatibleValueTypesException(std::string const & firstType, std::string const & secondType) : _msg("Values of types \"" + firstType + "\" and \"" + secondType + "\" are incompatible") {}

	inline char const * what() const noexcept { return _msg.c_str(); }
};

#endif
