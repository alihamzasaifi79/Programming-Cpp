#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;

    Employee(string n, int i, double s) {
        name=n;
        id=i;
        salary=s;
    }

    void display_emp() {
        cout<<"employee name: "<<name<<endl;
        cout<<"employee id: "<<id<<endl;
        cout<<"employee salary: "<<salary<<endl;
    }
};

class Manager: public Employee {
public:
    string department;

    Manager(string n, int i, double s, string d): Employee(n, i, s) {
        department=d;
    }

    void display_man() {
        display_emp();
        cout<<"manager department: "<<department<<endl;
    }
};

int main() {
    Employee emp1("Ali", 101, 50000);
    Manager mgr1("Raza", 102, 70000, "faculty");

    cout<<"employee details:"<<endl;
    emp1.display_emp();
    cout<<endl<<endl<<endl;

    cout<<"manager details:"<<endl;
    mgr1.display_man();

    return 0;
}

