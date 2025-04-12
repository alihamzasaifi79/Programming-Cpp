#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int pages;
    float price;
};

int main() {
    Book b;
    cout<<"enter the title of the book: ";
    getline(cin, b.title);
    cout<<"enter the author of the book: ";
    getline(cin, b.author);
    cout<<"enter the pages of the book: ";
    cin>>b.pages;
    cout<<"enter the price of the book: ";
    cin>>b.price;
    
    cout<<endl<<"Details of book are:"<<endl<<endl;
    
    cout<<"Title: "<<b.title<<endl;
    cout<<"Author: "<<b.author<<endl;
    cout<<"Pages: "<<b.pages<<endl;
    cout<<"Price: "<<b.price<<endl;

    return 0;
}
