#include<iostream>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(string n,int a):name(n),age(a){}
    void disp(){
        cout<<"name: "<<name<<", age: "<<age<<endl;
    }
};

class Student: public Person{
private:
    char grade;
public:
    Student(string n, int a, char g): Person(n, a), grade(g){}
    void display(){
        disp();
        cout<<"grade: "<<grade<<endl;
    }
};

int main(){
	string name;
	int age;
	char grade;
	cout<<"enter name: ";
	getline(cin, name);
	cout<<"enter age: ";
	cin>>age;
	cout<<"enter grade: ";
	cin>>grade;
	cin.ignore();
    Student s(name, age, grade);
    s.display();
    return 0;
}

