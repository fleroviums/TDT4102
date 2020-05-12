#pragma once
#include <utility>

class Dummy {
public:
	int *num;
	Dummy() {
		num = new int(0);
	}

	Dummy(const Dummy & rhs) : Dummy{} {
		*num = *rhs.num;
	}

	// Copy-Swap: Tar inn rhs som kopi, bytter medlemsvariable
	Dummy& operator=(Dummy rhs) {
		std::swap(this->num, rhs.num);
		return *this;
	}

	~Dummy() {
		delete num;
	}
};

void dummyTest();
