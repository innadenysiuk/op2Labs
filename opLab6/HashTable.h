#ifndef OPLAB6_HASHTABLE_H
#define OPLAB6_HASHTABLE_H

#include <iostream>
#include <cmath>

template<typename T>
int hash(T value, int capacity);

template<>
int hash(std::string value, int capacity);

template<>
int hash(double value, int capacity);

template<typename T, typename S>
struct Pair {
    int index = -1;
    T first;
    S second;
    Pair();
    Pair(T first, S second);
};

template<typename T, typename S>
class HashTable {
private:
    int capacity = 1000;
    size_t size = 0;
    Pair<T, S>* table;

public:
    class Iterator {
    private:
        HashTable<T, S>* hashTable;
        int currentIndex;

    public:
        Iterator(HashTable<T, S>* ht, int index);
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
        Pair<T, S>& operator*();
    };

    Iterator begin();
    Iterator end();

    HashTable();
    void put(T key, S value);
    S get(T key);
    void remove(T key);
    void clear();
    int getSize() const;
};

void menu();

void typeSelector(std::string& type);

template<typename T, typename S>
void testCases(HashTable<T, S>& map);

#endif //OPLAB6_HASHTABLE_H

