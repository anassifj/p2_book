#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    const int SIZE = 100;
    Book b(SIZE);
    b.add('c');
    b.add('b');

    cout << b.get('b') << endl;
    return 0;
}
