#include "Dummy.h"
#include <iostream>

void dummyTest() {
	Dummy a;
	*a.num = 4;
	Dummy b{ a };
	Dummy c;
	c = a;
	std::cout << "a: " << *a.num << std::endl;
	std::cout << "b: " << *b.num << std::endl;
	std::cout << "c: " << *c.num << std::endl;
	*b.num = 3;
	*c.num = 5;
	std::cout << "a: " << *a.num << std::endl;
	std::cout << "b: " << *b.num << std::endl;
	std::cout << "c: " << *c.num << std::endl;

	std::cin.get();
}
