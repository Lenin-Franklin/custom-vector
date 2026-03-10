#pragma once
#include <utility>
#include <cassert>
//#include <iostream>

template<typename T>
class Vector {
private:
	T* data;
	size_t size;
	size_t capacity;

public:
	Vector() { //constructor
		data = nullptr;
		size = 0;
		capacity = 0;
	}
	~Vector() { //destructor
		delete[] data;
	}

	Vector(const Vector& other) { //copy constructor
		size = other.size;
		capacity = other.capacity;

		data = new T[capacity];

		for (size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}

	Vector& operator=(const Vector& other) //copy assignment constructor
	{
		if (this == &other) {
			return *this;
		}

		delete[] data;

		size = other.size;
		capacity = other.capacity;

		data = new T[capacity];

		for (size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}

		return *this;
	}

	Vector(Vector&& other) noexcept { //Move constructor
		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}

	Vector& operator=(Vector&& other) noexcept { //Move assignment constructor
		if (this == &other) {
			return *this;
		}

		delete[] data;

		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;

		return *this;
	}


	void push_back(const T& value) { //push back logic
		if (size == capacity) {

			/*
			if (capacity == 0) {
				resize(1);
			}
			else {
				resize(capacity * 2);
			}
			*/

			resize();
		}
		data[size] = value;
		size++;

		//std::cout << "inserted element:" << value << std::endl;
	}

	void resize() { //resize logic

	

		size_t new_capacity = (capacity == 0) ? 1 : capacity * 2; //checking for initial memory allocation

		assert(new_capacity >= size);

		T* newData = new T[new_capacity]; //new memory allocation
		
		/*
		for (size_t i = 0; i < size; i++) { //copying old data to new memory location
			newData = data[i];
		}
		*/

		//we can use move semantics
		for (size_t i = 0; i < size && i<new_capacity; ++i) {
			newData[i] = std::move(data[i]);
		}

		delete[] data; // deleting old memory

		data = newData; //pointing to new memory location

		capacity = new_capacity;

	}

	T& operator[](size_t index) {
		return data[index];
	}

	size_t getSize() const {
		return size;
	}

	size_t getCapacity() const {
		return capacity;
	}

	//small improvement for bounds checking
	T& at(size_t index) {
		if (index >= size) {
			throw std::out_of_range("Index out of bounds");
		}

		return data[index];
	}
};