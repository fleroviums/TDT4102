#include "Dummy.h"
void dummyTest() {
Dummy a;
*a.num = 4;
Dummy b{a};
Dummy c;
c = a;
cout << "a: " << *a.num << endl;
cout << "b: " << *b.num << endl;
cout << "c: " << *c.num << endl;
*b.num = 3;
*c.num = 5;
cout << "a: " << *a.num << endl;
cout << "b: " << *b.num << endl;
cout << "c: " << *c.num << endl;
cin.get(); // For å hindre at
// programmet avslutter med en gang
}

Dummy::Dummy(const Dummy & other) : num{nullptr}
{
	this->num = new int{};
	*num = *other.num;
}

Dummy &Dummy::operator=(Dummy rhs)
{
	swap(num, rhs.num);
	return *this;
}
