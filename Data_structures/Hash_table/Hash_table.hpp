#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <functional>

#define ListIterator  typename std::list<std::pair<Key_t, Value_t>>::iterator
#define List std::list<std::pair<Key_t, Value_t>>

namespace hash_functions {

    template <typename Key_t>
    struct KeyHash;

    /// Hash for integer key type
    template <>
    struct KeyHash<int> {
        size_t operator()(int key) const {
            size_t hash = 5381;
            const unsigned char* data = reinterpret_cast<const unsigned char*>(&key);
            for (size_t i = 0; i < sizeof(int); ++i) {
                hash = ((hash << 5) + hash) + data[i]; // Hash = (hash * 33) + data[i]
            }
            return hash;
        }
    };

    /// Hash for std::string key type
    template <>
    struct KeyHash<std::string> {
        size_t operator()(const std::string& key) const {
            return std::hash<std::string>{}(key);
        }
    };
} // hash_functions

template<typename Key_t, typename Value_t>
class HashTable
{
    const size_t TABLE_DEFAULT_CAPACITY = 101; // Prime number

public:
    HashTable();
    HashTable(const size_t size);
    ~HashTable();

    // Copy semantics
    HashTable(const HashTable& obj);
    HashTable& operator=(const HashTable& obj);

    // Move semantics
    HashTable(HashTable&& obj);
    HashTable& operator=(HashTable&& obj);

    Value_t& operator[](const Key_t& key);
    void insertion(const Key_t& key, const Value_t& value); // Addotion
    void deletion(const Key_t& key);                        // Remove
    bool searchInTable(const Key_t& key) const;             // Search

    bool empty() const;
    void print() const;
    size_t size() const;
    size_t filled() const;
    void clear();

private:
    size_t hashing(const Key_t& key) const; // Key type can be integer or std::string
    ListIterator retrieval(List& list, const Key_t& key) const; // Return iterator to the pair in the list or nd iterator if key not found
    ListIterator findInList(List& list, const Key_t& key) const;
    void checkLoadFactor();
    void resizeTable();
    size_t getNextPrime(const size_t number) const;

private:
    size_t m_capacity = 0;
    size_t m_filled = 0;
    List* m_table;

    const float loadFactor = 0.5;
    hash_functions::KeyHash<Key_t> hash; // hashing
};

#endif // HASH_TABLE_HPP

