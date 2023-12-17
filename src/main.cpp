#include <iostream>
#include <string>

#include <IValue.hpp>
#include <AutoValue.hpp>
#include <NullValue.hpp>
#include <IntValue.hpp>

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

	std::cout << std::endl << a.nestCount() << ' ' << *aClone << std::endl;

	IValue * n = aClone;
	aClone->clear();
	std::cout << n->isNull() << std::endl;

	delete n;

	b.push_back(a);
	NullValue null;
	IntValue iv = 4;
	VectorValue vect{{&null, &iv}};
	b.push_back(vect);
	b.push_back(b);
	std::cout << b << std::endl;

	return 0;
}
