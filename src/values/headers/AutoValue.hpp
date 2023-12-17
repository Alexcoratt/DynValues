#ifndef AUTO_VALUE_HPP
#define AUTO_VALUE_HPP

#include <memory>

#include "IValue.hpp"

class AutoValue : public IValue {
private:
	std::shared_ptr<IValue> _value;

public:
	AutoValue();
	AutoValue(AutoValue const &);
	AutoValue(IValue const &);
	AutoValue(double);
	AutoValue(int);
	AutoValue(unsigned long);
	AutoValue(std::string const &);
	AutoValue(char const *);
	~AutoValue();

	int nestCount() const;
	void clear();

	AutoValue & operator=(AutoValue const &);

	void swap(AutoValue &);

	AutoValue * getClone() const override;

	bool operator<(IValue const &) const override;

	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isNull() const override;
	bool isInt() const override;
	bool isUnsignedLongInt() const override;
	bool isDouble() const override;
	bool isString() const override;
};

#endif
