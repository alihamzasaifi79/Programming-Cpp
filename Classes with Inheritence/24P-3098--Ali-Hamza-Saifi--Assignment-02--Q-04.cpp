#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;

    Book(string title, string author) {
        this->title = title;
        this->author = author;
    }
};

int main() {
    string title, author;
    cout<<"enter book title: ";
    getline(cin, title);
    cout<<"enter author's name: ";
    getline(cin, author);

    Book *ptr = new Book(title, author);

    cout<<"book title: "<<ptr->title<<", author: "<<ptr->author<<endl;

    delete ptr;

    return 0;
}

