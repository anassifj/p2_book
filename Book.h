//
// Created by eddy on 9/28/20.
//

#pragma once
using namespace std;

class Book {
public:
    static const int NOT_FOUND = -1;
    string **list;

    Book(int initialSize);   // Constuctor
    ~Book();  // we have a dtor so we need the whole big 4
    // Big 4: ctor, dtor, copy-ctor, assignment-op
    Book(const Book &other); // copy-ctor
    Book &operator=(const Book &rhs); // assignment
    void add(string isbn, string author, string title, string year);
    int get(string search) const; // look for search and return index
    int size() const;
private:
    const int ITEMS = 4; // Number of items for each book
    int capacity;  // how many elements can be in list
    int numElements = -1; // how may add's have happened

    void resize();
};
