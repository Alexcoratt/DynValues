#ifndef NULL_VALUE_HPP
#define NULL_VALUE_HPP

#include "IValue.hpp"

class NullValue : public IValue {
public:
	NullValue * getClone() const override;

	NullValue & operator=(NullValue const &);

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isNull() const override { return true; }
};

#endif
