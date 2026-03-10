#include <iostream>
#include "Vector.h"

void basicTest() {
	std::cout << "=== Basic Push Back Test ===\n";

	Vector<int> v;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}

	std::cout << "Size: " << v.getSize() << "\n";
	std::cout << "Capacity: " << v.getCapacity() << "\n";

	for (size_t i = 0; i < v.getSize(); ++i) {
		std::cout << v[i] << " ";
	}

	std::cout << "\n\n";
}

void copyTest() {
	std::cout << "=== Copy Constructor Test ===\n";

	Vector<int> a;

	a.push_back(10);
	a.push_back(20);
	a.push_back(30);

	Vector<int> b = a;

	std::cout << "Copied vector values:\n";

	for (size_t i = 0; i < b.getSize(); ++i) {
		std::cout << b[i] << " ";
	}

	std::cout << "\n\n";
}

void moveTest() {
	std::cout << "=== Move Constructor Test ===\n";

	Vector<int> a;

	a.push_back(100);
	a.push_back(200);

	Vector<int> b = std::move(a);

	std::cout << "Moved vector values:\n";

	for (size_t i = 0; i < b.getSize(); ++i) {
		std::cout << b[i] << " ";
	}

	std::cout << "\n\n";
}

int main() {

	std::cout << "Custom Vector Demostration\n\n";

	basicTest();

	copyTest();

	moveTest();

	std::cout << "All tests completed successfully.\n";

	return 0;
}