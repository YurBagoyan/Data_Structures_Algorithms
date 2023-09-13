# String Class Implementation

This repository contains a simple C++ implementation of a string class, named `String`. This `String` class provides basic string manipulation functionality, including constructors, copy and move semantics, operator overloads, and utility functions.

## Features

- Construct a string from a C-style string or create an empty string.
- Copy and move semantics for efficient string management.
- Overloaded operators for string concatenation, equality, and inequality.
- Access individual characters in the string using the `[]` operator.
- Retrieve the length of the string.
- Print the string to the standard output.

### Building

You can build the `String` class implementation using your preferred C++ compiler. Here's a simple example using g++:

```bash
g++ -std=c++11 String.cpp main.cpp -o string_demo
