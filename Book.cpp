//
// Created by eddy on 9/28/20.
//

#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(int initialSize) {
    capacity = initialSize;
    list = new int[capacity];
    numElements = 0;
}

Book::Book(const Book &other) {
    capacity = other.capacity;
    list = new int[capacity];
    numElements = other.numElements;
    for (int i = 0; i < numElements; i++)
        list[i] = other.list[i];
}


Book &Book::operator=(const Book &rhs) {
    cout << "in the assignment op overload" << endl;
    if (&rhs != this) {
        delete[] list;

        capacity = rhs.capacity;
        list = new int[capacity];
        numElements = rhs.numElements;
        for (int i = 0; i < numElements; i++)
            list[i] = rhs.list[i];
    }

    return *this;
}

Book::~Book() {
    delete[] list;
}

void Book::add(int item) {
    if (capacity == numElements)
        resize();
    list[numElements++] = item;
    cout << list[numElements] << endl;
}

int Book::size() const {
    return numElements;
}

int Book::get(int search) const {
    for (int i = 0; i < numElements; i++) {
        if (list[i] == search)
            return i;
    }
    return NOT_FOUND;  // sentinel value meaning not found
}

void Book::resize() {
    capacity *= 2;
    int *newList = new int[capacity];
    for (int i = 0; i < numElements; i++)
        newList[i] = list[i];
    delete[] list;
    list = newList;
}

