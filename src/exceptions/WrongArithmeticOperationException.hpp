#ifndef WRONG_ARITHMETIC_OPERATION_EXCEPTION_HPP
#define WRONG_ARITHMETIC_OPERATION_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class WrongArithmeticOperationException : public std::exception {
private:
	std::string _msg;

public:
	WrongArithmeticOperationException(std::string const & valueTypeName, std::string const & arithmeticOperationName) : _msg{"Unable to perform operation \"" + arithmeticOperationName + "\" for value of type " + valueTypeName} {}

	char const * what() const noexcept override { return _msg.c_str(); }
};

#endif
