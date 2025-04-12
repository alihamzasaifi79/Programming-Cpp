#include <iostream>
#include <cstring>
using namespace std;

class person {
public:
    char *name;

    person(const char *n) {
        name =new char[strlen(n)+1];
        strcpy(name, n);
    }

    person(person &p) {
        name= p.name;
        cout<<"shallow copy constructor called"<<endl;
    }

    person& operator=(person &p) {
        if(this==&p) {
		return *this;
		}
        delete[] name;
        name=new char[strlen(p.name)+1];
        strcpy(name, p.name);
        cout<<"deep copy assignment operator called"<<endl;
        return *this;
    }

    ~person() {
        delete[] name;
    }
};

int main() {
    person p1("Ali");
    person p2= p1;
    person p3("Raza");
    p3= p1;

    cout<<"p1 name: "<<p1.name<<endl;
    cout<<"p2 name: "<<p2.name<<endl;
    cout<<"p3 name: "<<p3.name<<endl;

    strcpy(p1.name, "changed name");

    cout<<"after changing p1 name: "<<endl;
    cout<<"p1 name: "<< p1.name<<endl;
    cout<<"p2 name: "<< p2.name<<endl;
    cout<<"p3 name: "<< p3.name<<endl;

    return 0;
}

