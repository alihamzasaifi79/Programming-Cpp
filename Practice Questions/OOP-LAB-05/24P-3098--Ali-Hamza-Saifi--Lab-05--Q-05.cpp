#include<iostream>
using namespace std;

struct Book{
    string title;
    string author;
    float price;
    int pub;
};

void inputbooks(Book* books,int n);
void dispbooks(Book* books,int n);
Book expbook(Book* books,int n);
void sortbooks(Book* books,int n);

int main(){
    int n;
    cout<<"enter number of books: ";
    cin>>n;
    cin.ignore();

    Book* books=new Book[n];

    inputbooks(books,n);
    cout<<endl;
    cout<<"all books details:"<<endl;
    dispbooks(books,n);

    Book expensive=expbook(books,n);
    cout<<"most expensive book details:"<<endl;
    cout<<"title: "<<expensive.title<<endl;
    cout<<"author: "<<expensive.author<<endl;
    cout<<"price: $"<<expensive.price<<endl;

    sortbooks(books,n);
    cout<<endl;
    cout<<"books sorted by publication year:"<<endl;
    dispbooks(books,n);

    delete[] books;
    books=NULL;
    return 0;
}

void sortbooks(Book* books,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(books[i].pub>books[j].pub){
                string ttitle = books[i].title;
                books[i].title = books[j].title;
                books[j].title = ttitle;

                string tauthor = books[i].author;
                books[i].author = books[j].author;
                books[j].author = tauthor;

                float tprice = books[i].price;
                books[i].price = books[j].price;
                books[j].price = tprice;

                int tpub = books[i].pub;
                books[i].pub = books[j].pub;
                books[j].pub = tpub;
            }
        }
    }
}

void dispbooks(Book* books,int n){
    for(int i=0;i<n;i++){
        cout<<"book "<<i+1<<" details:"<<endl;
        cout<<"title: "<<books[i].title<<endl;
        cout<<"author: "<<books[i].author<<endl;
        cout<<"price: $"<<books[i].price<<endl;
        cout<<"publication year: "<<books[i].pub<<endl<<endl;
    }
}

void inputbooks(Book* books,int n){
    for(int i=0;i<n;i++){
        cout<<"enter title of book "<<i+1<<": ";
        getline(cin,books[i].title);
        cout<<"enter author of book "<<i+1<<": ";
        getline(cin,books[i].author);
        cout<<"enter price of book "<<i+1<<": ";
        cin>>books[i].price;
        cin.ignore();
        cout<<"enter publication year of book "<<i+1<<": ";
        cin>>books[i].pub;
        cin.ignore();
    }
}

Book expbook(Book* books,int n){
    Book ex=books[0];
    for(int i=1;i<n;i++){
        if(books[i].price>ex.price){
            ex=books[i];
        }
    }
    return ex;
}

