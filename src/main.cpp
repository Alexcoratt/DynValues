#include <iostream>
#include <string>

#include <AbstractValue.hpp>
#include <AutoValue.hpp>
#include <NullValue.hpp>
#include <IntValue.hpp>
#include <VectorValue.hpp>
#include <DateValue.hpp>
#include <StringValue.hpp>
#include <DoubleValue.hpp>

#include <limits.h>

int main() {
	AutoValue a = 3;
	AutoValue b = "Hello";
	DateValue date(14, 9, 2005);

	std::cout << (b + (a + a) + a).getTypeName() << '\t' << (b + (a + a) + a) << std::endl;

	AutoValue test = ((b + (a + a) + a) * a + StringValue("hi") + date) * (AutoValue(date) / AutoValue(30000));
	std::cout << test << std::endl;

	std::cout << AutoValue(date) + AutoValue(1) << std::endl;

	return 0;
}
