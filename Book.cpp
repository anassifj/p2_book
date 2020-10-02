//
// Created by eddy on 9/28/20.
//

#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(int initialSize) {
    capacity = initialSize;
    list = new string*[capacity];
    bookId = 0;
}

Book::Book(const Book &other) {
    capacity = other.capacity;
    list = new string*[capacity];
    bookId = other.bookId;
    for (int i = 0; i < bookId; i++)
        list[i] = other.list[i];
}


Book &Book::operator=(const Book &rhs) {
    if (&rhs != this) {
        delete[] list;

        capacity = rhs.capacity;
        list = new string*[capacity];
        bookId = rhs.bookId;
        for (int i = 0; i < bookId; i++)
            list[i] = rhs.list[i];
    }

    return *this;
}

Book::~Book() {
    delete[] list;
}

void Book::add(string isbn, string author, string title, string year) {
    if (capacity == bookId)
        resize();

    list[bookId] = new string[ITEMS];
//    cout << "isbn " << isbn << " author " << author << endl;
    list[bookId][0] = isbn;
    list[bookId][1] = author;
    list[bookId][2] = title;
    list[bookId][3] = year;
    bookId++;
}

int Book::size() const {
    return bookId;
}

int Book::get(string search) const {
    for (int i = 0; i < bookId; i++) {
        if (list[i][0] == search)
            return i;
    }
    return NOT_FOUND;  // sentinel value meaning not found
}

void Book::resize() {
    string **newList = new string*[capacity];
    for (int i = 0; i < bookId; i++)
        for (int j = 0; j < ITEMS; j++)
            newList[i][j] = list[i][j];
    delete[] list;
    list = newList;
}

