#include "HashTable.h"

template<typename T>
int hash(T value, int capacity) {
    return std::abs(value) % capacity;
}

template<>
int hash(std::string value, int capacity) {
    int sum = 0;
    for (size_t i = 0; i < value.length(); i++) {
        sum += value[i];
    }
    return sum % capacity;
}

template<>
int hash(double value, int capacity) {
    return std::abs((int)value) % capacity;
}

template<typename T, typename S>
Pair<T, S>::Pair() : first(), second() {}

template<typename T, typename S>
Pair<T, S>::Pair(T first, S second) : first(first), second(second) {}

template<typename T, typename S>
typename HashTable<T, S>::Iterator HashTable<T, S>::begin() {
    int index = 0;
    while (index < capacity && table[index].index == -1) {
        index++;
    }
    return Iterator(this, index);
}

template<typename T, typename S>
typename HashTable<T, S>::Iterator HashTable<T, S>::end() {
    return Iterator(this, capacity);
}

template<typename T, typename S>
HashTable<T, S>::HashTable() : table(new Pair<T, S>[capacity]) {}

template<typename T, typename S>
void HashTable<T, S>::put(T key, S value) {
    int index = hash(key, capacity);
    while (table[index].index != -1) {
        index = (index + 1) % capacity;
    }
    table[index] = Pair<T, S>(key, value);
    table[index].index = index;
    size++;
}

template<typename T, typename S>
S HashTable<T, S>::get(T key) {
    int index = hash(key, capacity);
    int temp_index = index;
    while (table[index].index != -1) {
        if (table[index].first == key) {
            return table[index].second;
        }
        index = (index + 1) % capacity;
        if (index == temp_index) break;
    }
    throw std::invalid_argument("Element not found!");
}

template<typename T, typename S>
void HashTable<T, S>::remove(T key) {
    int index = hash(key, capacity);
    int temp_index = index;
    while (table[index].index != -1) {
        if (table[index].first == key) {
            table[index].index = -1;
            return;
        }
        index = (index + 1) % capacity;
        if (index == temp_index) break;
    }
    size--;
}

template<typename T, typename S>
void HashTable<T, S>::clear() {
    for (size_t i = 0; i < capacity; i++) {
        table[i].index = -1;
    }
    size = 0;
}

template<typename T, typename S>
int HashTable<T, S>::getSize() const {
    return size;
}

template<typename T, typename S>
HashTable<T, S>::Iterator::Iterator(HashTable<T, S>* ht, int index) : hashTable(ht), currentIndex(index) {}

template<typename T, typename S>
typename HashTable<T, S>::Iterator& HashTable<T, S>::Iterator::operator++() {
    currentIndex++;
    while (currentIndex < hashTable->capacity && hashTable->table[currentIndex].index == -1) {
        currentIndex++;
    }
    return *this;
}

template<typename T, typename S>
bool HashTable<T, S>::Iterator::operator!=(const Iterator& other) const {
    return currentIndex != other.currentIndex;
}

template<typename T, typename S>
Pair<T, S>& HashTable<T, S>::Iterator::operator*() {
    return hashTable->table[currentIndex];
}

void menu() {
    std::cout << "Please, enter type of the key of HashTable:\n" << std::endl;
    std::cout << "* string => string - string" << std::endl;
    std::cout << "* int => int - string" << std::endl;
    std::cout << "* double => double - string" << std::endl;
    std::cout << "* si => string - int" << std::endl;
    std::cout << "* ii => int - int" << std::endl;
}

void typeSelector(std::string& type) {
    if (type == "string") {
        HashTable<std::string, std::string> table;
        testCases(table);
    }
    else if (type == "int") {
        HashTable<int, std::string> table;
        testCases(table);
    }
    else if (type == "double") {
        HashTable<double, std::string> table;
        testCases(table);
    }
    else if (type == "si") {
        HashTable<std::string, int> table;
        testCases(table);
    }
    else if (type == "ii") {
        HashTable<int, int> table;
        testCases(table);
    }
}

template<typename T, typename S>
void testCases(HashTable<T, S>& map) {
    int operation;
    while (true) {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Put element into map" << std::endl;
        std::cout << "2. Get element from map" << std::endl;
        std::cout << "3. Clear map" << std::endl;
        std::cout << "4. Print using iterator" << std::endl;
        std::cout << "5. Remove element by key" << std::endl;
        std::cout << "6. Get size of map" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "> ";
        std::cin >> operation;

        if (operation == 0) break;
        switch (operation) {
            case 1: {
                T key;
                S value;
                std::cout << "Enter key and value: " << std::endl;
                std::cout << "Key: ";
                std::cin >> key;
                std::cout << "Value: ";
                std::cin >> value;
                map.put(key, value);
                std::cout << "Element put into map." << std::endl;
                break;
            }
            case 2: {
                T key;
                std::cout << "Enter key: ";
                std::cin >> key;
                try {
                    std::cout << "Value: " << map.get(key) << std::endl;
                }
                catch (const std::invalid_argument& exception) {
                    std::cout << exception.what();
                }
                break;
            }
            case 3: {
                map.clear();
                std::cout << "Map cleared" << std::endl;
                break;
            }
            case 4: {
                std::cout << "Map: " << std::endl;
                for (auto i : map) {
                    std::cout << i.first << " => " << i.second << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Enter key: ";
                T key;
                std::cin >> key;
                std::cout << "Element " << key << " removed" << std::endl;
                map.remove(key);
                break;
            }
            case 6: {
                std::cout << "Size of the map: " << map.getSize() << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid operation." << std::endl;
            }
        }

    }
}
