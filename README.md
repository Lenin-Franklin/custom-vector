# Custom Vector Implementation (C++)

A simplified implementation of the C++ `std::vector` container built from scratch to understand dynamic memory management, copy/move semantics, and container growth strategies.

This project demonstrates core systems programming concepts used in high-performance backend and systems software.

---

## Features

The custom vector supports:

* Dynamic array resizing
* `push_back()` insertion
* Amortized constant-time growth
* Element access via `operator[]`
* Copy constructor (deep copy)
* Copy assignment operator
* Move constructor
* Move assignment operator
* Proper memory cleanup using RAII

---

## Concepts Demonstrated

This project showcases several important C++ concepts:

* Dynamic memory allocation (`new[]`, `delete[]`)
* RAII (Resource Acquisition Is Initialization)
* Deep vs shallow copying
* Move semantics (`std::move`)
* The **Rule of Five**
* Amortized time complexity
* Template-based containers

---

## Project Structure

```
custom-vector
│
├── include
│   └── Vector.h
│
├── src
│   └── main.cpp
│
├── CMakeLists.txt
└── README.md
```

---

## Example Usage

```cpp
Vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

for(size_t i = 0; i < v.getSize(); i++)
{
    std::cout << v[i] << std::endl;
}
```

Output:

```
10
20
30
```

---

## How It Works

The vector grows using an exponential strategy:

```
capacity: 1 → 2 → 4 → 8 → 16 ...
```

When the container becomes full:

1. A larger memory block is allocated
2. Existing elements are moved to the new block
3. Old memory is released
4. The container continues inserting elements

This ensures `push_back()` runs in **amortized O(1)** time.

---

## How to Build

This project uses **CMake**.

```
mkdir build
cd build
cmake ..
cmake --build .
```

Run the executable:

```
./vector_app
```

---

## Why This Project Exists

The goal of this project is to understand how standard containers like `std::vector` work internally.

Reimplementing core data structures helps build deeper understanding of:

* memory ownership
* performance characteristics
* container design

These concepts are essential in systems programming, backend engineering, and performance-critical applications.

---

## Future Improvements

Possible enhancements:

* Iterator support
* Bounds-checked access (`at()`)
* `pop_back()`
* `clear()`
* unit tests

---
