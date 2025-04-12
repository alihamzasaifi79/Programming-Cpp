#include<iostream>
using namespace std;

struct Book{
    string title;
    string author;
    float price;
};

int main(){
    Book books[5];
    for(int i=0;i<5;i++){
        cout<<"enter title of book "<<i+1<<": ";
        getline(cin,books[i].title);
        cout<<"enter author of book "<<i+1<<": ";
        getline(cin,books[i].author);
        cout<<"enter price of book "<<i+1<<": ";
        cin>>books[i].price;
        cin.ignore();
    }
    cout<<"books with price greater than $500:"<<endl;
    for(int i=0;i<5;i++){
        if(books[i].price>500){
            cout<<"title: "<<books[i].title<<endl;
            cout<<"author: "<<books[i].author<<endl;
            cout<<"price: $"<<books[i].price<<endl<<endl;
        }
    }
    return 0;
}

