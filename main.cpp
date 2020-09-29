#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

void printList(Book b) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < 4; j++) {
//            cout << i;
            cout << b.list[b.get(to_string(i))][j] << ", ";
        }
        cout << endl;
    }
}

void readFile() {
    const int SIZE = 100;
    Book b(SIZE);

    // Initialize variables to read file
    string str, filepath;
    ifstream inFile;
    string filename;
    filename = "/home/eddy/Downloads/books.txt"; // For testing
//    cout << "Enter book file: ";
//    cin >> filename;
    cout << filename << endl;
    inFile.open(filename);

    // Book variables
    int isbn = 0;
    int counter = 0;
    string author, title, year;

    // Iterate through file
    if (inFile) {
        while (getline(inFile, str, ',')) {
            if (counter == 0)
                author = str;
            else if (counter == 1)
                title = str;
            else if (counter == 2) {
                year = str;
                b.add(to_string(isbn), author, title, year);
                isbn++;
                counter = -1;
            }
            counter++;
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
