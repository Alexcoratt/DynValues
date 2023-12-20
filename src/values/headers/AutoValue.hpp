#ifndef AUTO_VALUE_HPP
#define AUTO_VALUE_HPP

#include <memory>
#include <vector>

#include "IValue.hpp"

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

	void clear();

	AutoValue & operator=(AutoValue const &);

	void swap(AutoValue &);

	// cloning
	AutoValue * getClone() const override;

	// comparison
	bool operator<(IValue const &) const override;

	// vector methods
	IValue & operator[](std::size_t const & index) override;
	IValue & at(std::size_t const & index) override;
	IValue const & at(std::size_t const & index) const override;
	IValue & back() override;
	IValue const & back() const override;

	void push_back(IValue const & value) override;
	void pop_back() override;
	std::size_t size() const override;
	bool empty() const override;

	// transformation
	std::string toString() const override;
	char toChar() const override;
	double toDouble() const override;
	int toInt() const override;
	unsigned long toUnsignedLongInt() const override;

	// typechecking
	bool isNull() const override;
	bool isInt() const override;
	bool isUnsignedLongInt() const override;
	bool isDouble() const override;
	bool isString() const override;
	bool isChar() const override;
	bool isIterable() const override;

	std::string getTypeName() const override;
};

#endif
