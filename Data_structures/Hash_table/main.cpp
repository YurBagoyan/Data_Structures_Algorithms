#include "Hash_table.hpp"

int main() {
    // Test with an integer key and integer value
    HashTable<int, int> intTable;
    intTable.insertion(1, 10);
    intTable.insertion(2, 20);
    intTable.insertion(30, 65);
    intTable.insertion(10, 30);

    std::cout << "Integer Table:" << std::endl;
    intTable.print();

    int keyToFind = 2; 
    if (intTable.searchInTable(keyToFind)) {
        std::cout << "Found key " << keyToFind << ": " << intTable[keyToFind] << std::endl;
    }
    else {
        std::cout << "Key " << keyToFind << " not found" << std::endl;
    }

    // Test with a string key and string value
    HashTable<std::string, std::string> stringTable;
    stringTable.insertion("apple", "red");
    stringTable.insertion("banana", "yellow");
    stringTable.insertion("grape", "purple");

    std::cout << "\nString Table:" << std::endl;
    stringTable.print();

    std::string stringKeyToFind = "banana";
    if (stringTable.searchInTable(stringKeyToFind)) {
        std::cout << "Found key " << stringKeyToFind << ": " << stringTable[stringKeyToFind] << std::endl;
    }
    else {
        std::cout << "Key " << stringKeyToFind << " not found" << std::endl;
    }

    // Test deletion
    intTable.deletion(2);
    stringTable.deletion("banana");

    std::cout << "\nAfter Deletion:" << std::endl;
    intTable.print();
    stringTable.print();

    return 0;
}
