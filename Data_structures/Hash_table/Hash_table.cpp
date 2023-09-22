#include "Hash_table.hpp"

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>::HashTable()
{
    m_capacity = TABLE_DEFAULT_CAPACITY; // 101
    m_table = new List[m_capacity];
}

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>::HashTable(const size_t size)
{
    m_capacity = getNextPrime(size);
    m_table = new List[m_capacity];
}

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>::~HashTable()
{
    delete[] m_table;
}

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>::HashTable(const HashTable& obj)
{
    if (this != &obj) {
        m_capacity = obj.m_capacity;
        m_filled = obj.m_filled;
        m_table = new List[m_capacity];

        for (size_t i = 0; i < m_capacity; ++i) {
            for (const auto& pair : obj.m_table[i]) {
                m_table[i].push_back(pair);
            }
        }
    }
}

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>& HashTable<Key_t, Value_t>::operator=(const HashTable& obj)
{
    if (this != &obj) {
        delete[] m_table;

        m_capacity = obj.m_capacity;
        m_filled = obj.m_filled;
        m_table = new List[m_capacity];

        for (size_t i = 0; i < m_capacity; ++i) {
            for (const auto pair : obj.m_table[i]) {
                m_table[i].push_back(pair);
            }
        }
    }

    return *this;
}

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>::HashTable(HashTable&& obj)
{
    if (this != &obj) {
        m_capacity = obj.m_capacity;
        m_filled = obj.m_filled;
        m_table = obj.m_table;

        obj.m_capacity = 0;
        obj.m_filled = 0;
        obj.m_table = nullptr;
    }
}

template <typename Key_t, typename Value_t>
HashTable<Key_t, Value_t>& HashTable<Key_t, Value_t>::operator=(HashTable&& obj)
{
    if (this != &obj) {
        delete[] m_table;

        m_capacity = obj.m_capacity;
        m_filled = obj.m_filled;
        m_table = obj.m_table;

        obj.m_capacity = 0;
        obj.m_filled = 0;
        obj.m_table = nullptr;
    }

    return *this;
}

template <typename Key_t, typename Value_t>
size_t HashTable<Key_t, Value_t>::hashing(const Key_t& key) const
{
    size_t hashed = hash(key);

    if (hashed > m_capacity) {
        return (hashed % m_capacity);
    }

    return hashed;
}

template <typename Key_t, typename Value_t>
Value_t& HashTable<Key_t, Value_t>::operator[](const Key_t& key) 
{
    const size_t index = hashing(key);
    if (m_table[index].empty()) {
        // List is empty, throw an exception
        throw std::out_of_range("Key not found");
    }

    ListIterator it = retrieval(m_table[index], key);

    if (it == m_table[index].end()) {        
        // Key in list not found, throw an exception
        throw std::out_of_range("Key not found");
    }

    // Key found, return a reference to its associated value
    return it->second;
}

template <typename Key_t, typename Value_t>
void HashTable<Key_t, Value_t>::insertion(const Key_t& key, const Value_t& value)
{
    // Ckeck if table already have element with this key, change value and return
    const size_t index = hashing(key);
    if (!m_table[index].empty()) {

        ListIterator it = retrieval(m_table[index], key);
        if (it != m_table[index].end()) {
            it->second = value;
            return;
        }
    }

    checkLoadFactor();

    const std::pair<Key_t, Value_t> myPair(key, value);
    m_table[index].push_back(myPair);
    ++m_filled;
}

template <typename Key_t, typename Value_t>
void HashTable<Key_t, Value_t>::deletion(const Key_t& key)
{
    const size_t index = hashing(key);
    if (m_table[index].empty()) {
        return;
    }

    ListIterator it = findInList(m_table[index], key);
    if (it != m_table[index].end()) {
        m_table[index].erase(it);
    }
    --m_filled;
}

template <typename Key_t, typename Value_t>
bool HashTable<Key_t, Value_t>::searchInTable(const Key_t& key) const
{
    const size_t index = hashing(key);
    if (m_table[index].empty()) {
        return false;
    }

    const ListIterator it = retrieval(m_table[index], key);
    if(it != m_table[index].end()){
        return true;
    }

    return false;
}

template <typename Key_t, typename Value_t>
ListIterator HashTable<Key_t, Value_t>::retrieval(List& list, const Key_t& key) const
{
    const ListIterator it = findInList(list, key);
    if (it != list.end()) {
        return it;  // Return iterator to the pair in the list
    }

    return list.end(); // Return end iterator if key not found
}

template <typename Key_t, typename Value_t>
ListIterator HashTable<Key_t, Value_t>::findInList(List& list, const Key_t& key) const
{
    ListIterator it = list.begin();
    while (it != list.end()) {
        if (it->first == key) {
            return it;
        }
        ++it; 
    }
    return list.end(); // Return end if not found
}

template <typename Key_t, typename Value_t>
bool HashTable<Key_t, Value_t>::empty() const
{
    return !m_filled;
}

template <typename Key_t, typename Value_t>
void HashTable<Key_t, Value_t>::print() const
{
    for (size_t i = 0; i < m_capacity; ++i) {
        std::cout << "Bucket " << i << ": ";

        for (const auto& pair : m_table[i]) {
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }

        std::cout << std::endl;
    }
    std::cout << "\n\n";
}

template <typename Key_t, typename Value_t>
size_t HashTable<Key_t, Value_t>::size() const
{
    return m_capacity;
}

template <typename Key_t, typename Value_t>
size_t HashTable<Key_t, Value_t>::filled() const
{
    return m_filled;
}

template <typename Key_t, typename Value_t>
void HashTable<Key_t, Value_t>::clear()
{
    for (size_t i = 0; i < m_capacity; ++i) {
        m_table[i].clear(); // Clear each list
    }

    m_filled = 0; // Reset the number of filled elements to zero
}

template <typename Key_t, typename Value_t>
void HashTable<Key_t, Value_t>::checkLoadFactor()
{
    // if half of table is full
    if (float(m_filled) / m_capacity > loadFactor) {
        resizeTable();
    }
}

template <typename Key_t, typename Value_t>
void HashTable<Key_t, Value_t>::resizeTable()
{
    size_t oldSize = m_capacity;
    m_capacity = getNextPrime(2 * m_capacity);
    List* newTable = new List[m_capacity];

    // Rehash and insert elements from the old table into the new table
    for (size_t i = 0; i < oldSize; ++i) {

        //for (const typename ListPair::iterator& pair : m_table[i]) {

        for (const auto& pair : m_table[i]) {

            size_t newIndex = hashing(pair.first); // Rehash
            newTable[newIndex].push_back(pair); // Insert into the new table
        }
    }

    // Delete the old table and update the capacity
    delete[] m_table;
    m_table = newTable;
}

bool isPrime(size_t n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (size_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

template <typename Key_t, typename Value_t>
size_t HashTable<Key_t, Value_t>::getNextPrime(size_t number) const
{
    if (number <= 1) return 2;
    if (number == 2) return 3;

    number = (number % 2 == 0) ? number + 1 : number; // Ensure n is odd

    while (true) {
        if (isPrime(number)) return number;
        number += 2; // Increment by 2 to check only odd numbers
    }
}



// Explicit instantiations for Key_t: int, Value_t: int
template class HashTable<int, int>;
template class HashTable<int, float>;
template class HashTable<int, double>;
template class HashTable<int, std::string>;
template class HashTable<int, char>;
template class HashTable<int, bool>;

// Explicit instantiations for Key_t: std::string, Value_t: int
template class HashTable<std::string, int>;
template class HashTable<std::string, float>;
template class HashTable<std::string, double>;
template class HashTable<std::string, std::string>;
template class HashTable<std::string, char>;
template class HashTable<std::string, bool>;

