#include <iostream>
#include <string>

#include <IValue.hpp>
#include <AutoValue.hpp>
#include <NullValue.hpp>
#include <IntValue.hpp>
#include <VectorValue.hpp>
#include <DateValue.hpp>

#include <limits.h>

int main() {
	AutoValue a = 3;
	AutoValue b = "Hello";
	AutoValue c;

	std::cout << a << ' ' << b << ' ' << c << std::endl;

	a = "World";
	std::cout << a << ' ';

	b = 2.43;
	std::cout << b << ' ';

	c = -21.32;
	std::cout << c << ' ';

	auto aClone = a.getClone();

	IValue * n = aClone;
	aClone->clear();
	std::cout << n->isNull() << ' ' << n->getTypeName() << std::endl;

	delete n;

	std::cout << a << ' ' << a.getTypeName() << ' ' << a.at(1) << ' ' << a.at(1).getTypeName() << std::endl;
	b = VectorValue{{&b}};
	b.push_back(a);
	b.push_back(b);
	std::cout << b << ' ' << b.getTypeName() << std::endl;
	std::cout << b[0] << ' ' << b.at(0).getTypeName() << std::endl;
	std::cout << b.at(1) << ' ' << b[1].getTypeName() << std::endl;
	b = (IValue *)&b;
	b = b;
	b = (IValue *)&b;
	b = (IValue *)&b;
	b = (IValue *)&b;
	b = (IValue *)&b;
	b = (IValue *)&b;
	b = (IValue *)&b;
	std::cout << b << ' ' << b.getTypeName() << std::endl;

	std::cout << "\nDateValue tests\n";
	DateValue date;
	std::cout << date << std::endl;
	date.set(365, 13, 2015);
	std::cout << date << ' ' << date.toUnsignedLongInt() << std::endl;
	DateValue date1(ULONG_MAX);
	std::cout << date1 << std::endl;
	std::cout << (date > date1) << std::endl;

	return 0;
}
