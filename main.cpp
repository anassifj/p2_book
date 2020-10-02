#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Book.h"
using namespace std;

void printList(Book b) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << b.list[b.get(to_string(i))][j] << ", ";
        }
        cout << b.list[b.get(to_string(i))][3];
        cout << endl;
    }
}

void readFile() {
    const int SIZE = 100;
    Book b(SIZE);

    // Initialize variables to read file
    string str, item, filepath;
    ifstream inFile;
    string filename;
    cout << "Enter book file: ";
    cin >> filename;
    cout << filename << endl;
    inFile.open(filename);

    // Book variables
    int isbn = 0;
    int counter = 0;
    string author, title, year;

    // Iterate through file
    if (inFile) {
        while (getline(inFile, str)) {
            istringstream line(str);
            while (getline(line, item, ',')) {
                if (counter == 0)
                    author = item;
                else if (counter == 1)
                    title = item;
                else if (counter == 2) {
                    year = item;
                    string isbnString = to_string(isbn);
                    b.add(isbnString, author, title, year);
                    isbn++;
                    counter = -1;  // -1 so it becomes 0 at line end
                }
                counter++;
            }
        }
        printList(b);
    } else {
        cout << "ERROR: cannot open file.\n";
    }
    inFile.close();
}

int main() {

    readFile();
    return 0;
}
