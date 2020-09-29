//
// Created by eddy on 9/28/20.
//

#pragma once

class Book {
public:
    static const int NOT_FOUND = -1;

    Book(int initialSize);   // Constuctor
    ~Book();  // we have a dtor so we need the whole big 4
    // Big 4: ctor, dtor, copy-ctor, assignment-op
    Book(const Book &other); // copy-ctor
    Book &operator=(const Book &rhs); // assignment
    void add(int item); // add item to list
    int get(int search) const; // look for search and return index
    int size() const;
private:
    int *list;
    int capacity;  // how many elements can be in list
    int numElements; // how may add's have happened

    void resize();
};
