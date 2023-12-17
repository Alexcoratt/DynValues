#ifndef AUTO_VALUE_HPP
#define AUTO_VALUE_HPP

#include <memory>
#include <vector>

#include "IValue.hpp"
#include "VectorValue.hpp"

class AutoValue : public IValue {
private:
	std::shared_ptr<IValue> _value;

public:
	AutoValue();
	AutoValue(AutoValue const &);
	AutoValue(IValue const &);
	AutoValue(IValue const *);
	AutoValue(double);
	AutoValue(int);
	AutoValue(unsigned long);
	AutoValue(std::string const &);
	AutoValue(char const *);
	AutoValue(std::vector<IValue const *> const & values);
	~AutoValue();

	int nestCount() const;
	void clear();

	AutoValue & operator=(AutoValue const &);

	void swap(AutoValue &);

	AutoValue * getClone() const override;

	bool operator<(IValue const &) const override;

	// vector methods
	IValue & operator[](std::size_t const & index);
	IValue & at(std::size_t const & index);
	IValue const & at(std::size_t const & index) const;
	IValue & back();
	IValue const & back() const;

	void push_back(IValue const & value);
	void pop_back();
	std::size_t size() const;
	bool empty() const;

	// type transformation methods
	operator std::string() const override;
	operator double() const override;
	operator int() const override;
	operator unsigned long() const override;

	bool isNull() const override;
	bool isInt() const override;
	bool isUnsignedLongInt() const override;
	bool isDouble() const override;
	bool isString() const override;
	bool isVector() const override;
};

#endif
