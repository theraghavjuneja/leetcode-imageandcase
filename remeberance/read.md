# README: 2D Vector in C++

## Introduction
A **2D vector** in C++ is essentially a vector of vectors, which allows us to create a dynamic matrix-like data structure. It is part of the C++ Standard Library (`std::vector`).

## Declaration
A 2D vector can be declared as follows:
```cpp
std::vector<std::vector<int>> vec(rows, std::vector<int>(cols, initial_value));
'''
Remember inside bracket i just have rows,vector<int>without name
'''
```
Here, `rows` defines the number of rows, `cols` defines the number of columns, and `initial_value` is the default value for each element.

