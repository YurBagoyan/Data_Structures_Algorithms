# Custom Hash Table Implementation

This is a custom hash table implementation in C++ that provides a flexible data structure for mapping keys to values. It is designed to work with various key and value types, including integers, floats, doubles, strings, characters, and booleans.

## Features

- Support for different key and value types using C++ templates.
- Custom hash functions for `int` and `std::string` key types.
- Operations:
  - Insertion of key-value pairs.
  - Deletion of key-value pairs.
  - Searching for keys in the hash table.
  - Resizing to maintain an efficient load factor.
- Copy and move semantics for efficient data management.
- Print function to visualize the contents of the hash table.

## Usage

To use this custom hash table in your C++ projects, follow these steps:

1. Include the `Hash_table.hpp` header file in your project.

2. Instantiate the `HashTable` class with the desired key and value types. For example:
   ```cpp
   // Instantiate a hash table for integers
   HashTable<int, int> intTable;

   // Instantiate a hash table for strings
   HashTable<std::string, std::string> stringTable;

3. Use the available operations to work with the hash table:
- insertion(key, value): Add key-value pairs.
- deletion(key): Remove key-value pairs by key.
- searchInTable(key): Check if a key exists in the hash table.
- operator[](key): Access values by key.

4. You can also customize the hash functions for specific key types by modifying the hash_functions namespace in the Hash_table.hpp header.
