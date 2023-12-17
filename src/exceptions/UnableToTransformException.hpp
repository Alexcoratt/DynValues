#ifndef UNABLE_TO_TRANSFORM_EXCEPTION_HPP
#define UNABLE_TO_TRANSFORM_EXCEPTION_HPP

#include <stdexcept>

class UnableToTransformException : public std::exception {
private:
	std::string _msg;

public:
	UnableToTransformException(std::string sourceType, std::string targetType) : _msg("Unable to transform value of type " + sourceType + " to value of type " + targetType) {}

	UnableToTransformException(std::string sourceType, std::string targetType, std::string currentValue) : _msg("Unable to transform value \"" + currentValue + "\" of type " + sourceType + " to value of type " + targetType) {}

	char const * what() const noexcept override { return _msg.c_str(); }
};

#endif
