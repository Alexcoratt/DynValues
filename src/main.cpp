#include <iostream>
#include <string>

#include <IValue.hpp>
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
	std::cout << (b * a + StringValue("hi") + date) * (AutoValue(date) / AutoValue(30000)) << std::endl;

	return 0;
}
