#include<iostream>
using namespace std;

struct Student{
    string name;
    int rollno;
    float marks;
};

int main(){
    int n;
    cout<<"enter number of students: ";
    cin>>n;

    Student* students = new Student[n];

    for(int i=0;i<n;i++){
        cout<<"enter name of student "<<i+1<<": ";
        cin.ignore();
        getline(cin,students[i].name);
        cout<<"enter roll number of student "<<i+1<<": ";
        cin>>students[i].rollno;
        cout<<"enter marks of student "<<i+1<<": ";
        cin>>students[i].marks;
    }

    cout<<"student details:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"name: "<<students[i].name<<endl;
        cout<<"roll no: "<<students[i].rollno<<endl;
        cout<<"marks: "<<students[i].marks<<endl<<endl;
    }

    delete[] students;
    students = NULL;

    return 0;
}

