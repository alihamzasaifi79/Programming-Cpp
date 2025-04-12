#include<iostream>
using namespace std;

struct Employee{
    string name;
    int id;
    float salary;
};

int main(){
    Employee emp;
    Employee* ptr = &emp;

    cout<<"enter name of employee: ";
    getline(cin, ptr->name);
    cout<<"enter id of employee: ";
    cin>>ptr->id;
    cout<<"enter salary of employee: ";
    cin>>ptr->salary;

    cout<<"name: "<<ptr->name<<endl;
    cout<<"id: "<<ptr->id<<endl;
    cout<<"salary: $"<<ptr->salary<<endl;

    return 0;
}

