#include <iostream>
#include <string>

#include <IValue.hpp>
#include <AutoValue.hpp>

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

	return 0;
}
