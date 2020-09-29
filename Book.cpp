//
// Created by eddy on 9/28/20.
//

#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(int initialSize) {
    capacity = initialSize;
    list = new string*[capacity];
    numElements = 0;
}

Book::Book(const Book &other) {
    capacity = other.capacity;
    list = new string*[capacity];
    numElements = other.numElements;
    for (int i = 0; i < numElements; i++)
        list[i] = other.list[i];
}


Book &Book::operator=(const Book &rhs) {
    if (&rhs != this) {
        delete[] list;

        capacity = rhs.capacity;
        list = new string*[capacity];
        numElements = rhs.numElements;
        for (int i = 0; i < numElements; i++)
            list[i] = rhs.list[i];
    }

    return *this;
}

Book::~Book() {
    delete[] list;
}

void Book::add(string isbn, string author, string title, string year) {
    if (capacity == numElements)
        resize();

    list[numElements] = new string[ITEMS];
    list[numElements][0] = isbn;
    list[numElements][1] = author;
    list[numElements][2] = title;
    list[numElements][3] = year;
    numElements++;
}

int Book::size() const {
    return numElements;
}

int Book::get(string search) const {
    for (int i = 0; i < numElements; i++) {
        if (list[i][0] == search)
            return i;
    }
    return NOT_FOUND;  // sentinel value meaning not found
}

void Book::resize() {
    string **newList = new string*[capacity];
    for (int i = 0; i < numElements; i++)
        for (int j = 0; j < ITEMS; j++)
            newList[i][j] = list[i][j];
    delete[] list;
    list = newList;
}

