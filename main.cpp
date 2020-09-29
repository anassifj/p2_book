#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    const int SIZE = 100;
    Book b(SIZE);
    b.add("1", "foo", "bar", "1997");
//    b.add(2, "foo", "bar", 1997);
//
    for (int i =0; i< 4; i++) {
        cout << b.list[b.get("1")][i] << " ";
    }
    return 0;
}
