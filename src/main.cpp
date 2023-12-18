#include <iostream>
#include <string>

#include <IValue.hpp>
#include <AutoValue.hpp>
#include <NullValue.hpp>
#include <IntValue.hpp>
#include <VectorValue.hpp>

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
	std::cout << n->isNull() << ' ' << n->getTypeName() << std::endl;

	delete n;

	b = VectorValue{{&b}};
	b.push_back(a);
	b.push_back(b);
	std::cout << b << ' ' << b.getTypeName() << std::endl;
	std::cout << b[0] << ' ' << b.at(0).getTypeName() << std::endl;
	std::cout << b.at(1) << ' ' << b[1].getTypeName() << std::endl;

	return 0;
}
