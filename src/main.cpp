#include <iostream>
#include "Vector.h"

int main() {

	/*
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	std::cout << "Inserted elements\n";

	*/

	Vector<int> v;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}

	/*for (int i = 0; i < 10; ++i) {
		std::cout << v[i] << "\n";
	}*/

	std::cout << "size: " << v.getSize() << "\n";
	std::cout << "capacity: " << v.getCapacity() << "\n";


	return 0;
}