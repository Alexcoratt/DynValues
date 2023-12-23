#ifndef AUTO_VALUE_HPP
#define AUTO_VALUE_HPP

#include <memory>
#include <vector>

#include "AbstractValue.hpp"

class AutoValue : public AbstractValue {
private:
	std::shared_ptr<AbstractValue> _value;

public:
	AutoValue();
	AutoValue(AutoValue const &);
	AutoValue(AbstractValue const &);
	explicit AutoValue(AbstractValue const *);
	AutoValue(double);
	AutoValue(int);
	AutoValue(unsigned long);
	AutoValue(std::string const &);
	AutoValue(char const *);
	AutoValue(std::vector<AbstractValue const *> const & values);
	~AutoValue();

	void clear();

	AutoValue & operator=(AutoValue const &);

	void swap(AutoValue &);

	// cloning
	AutoValue * getClone() const override;

	// comparison
	bool operator<(AbstractValue const &) const override;

	// vector methods
	AbstractValue & operator[](std::size_t const & index) override;
	AbstractValue & at(std::size_t const & index) override;
	AbstractValue const & at(std::size_t const & index) const override;
	AbstractValue & back() override;
	AbstractValue const & back() const override;

	void push_back(AbstractValue const & value) override;
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
	bool isDate() const override;

	std::string getTypeName() const override;

	// arithmetic operations
	AutoValue * add(AbstractValue const * other) const override;
	AutoValue * sub(AbstractValue const * other) const override;
	AutoValue * mul(AbstractValue const * other) const override;
	AutoValue * div(AbstractValue const * other) const override;

	// arithmetical operators
	AutoValue operator+(AbstractValue const & other) const;
	AutoValue operator-(AbstractValue const & other) const;
	AutoValue operator*(AbstractValue const & other) const;
	AutoValue operator/(AbstractValue const & other) const;
};

#endif
