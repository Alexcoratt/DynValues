#ifndef NON_ITERABLE_VALUE_TYPE_EXCEPTION_HPP
#define NON_ITERABLE_VALUE_TYPE_EXCEPTION_HPP

#include <string>
#include <exception>

class NonIterableValueTypeException : public std::exception {
private:
	std::string _msg;

public:
	NonIterableValueTypeException(std::string const & valueTypeName) : _msg("value of type " + valueTypeName + " is not iterable") {}

	char const * what() const noexcept override { return _msg.c_str(); }
};

#endif
