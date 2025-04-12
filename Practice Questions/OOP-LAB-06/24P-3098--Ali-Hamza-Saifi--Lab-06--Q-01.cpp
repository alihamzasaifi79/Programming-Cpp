#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll_no;
    int smarks[3];
    int tmarks;
    float avgmarks;

public:
    void input(int i) {
        cout << "enter student "<<i+1<<" name: ";
        cin>>name;
        cout<<"enter student "<<i+1<<" roll number: ";
        cin>>roll_no;
        tmarks = 0;
        for (int j = 0; j < 3; j++) {
            cout<<"enter student "<<i+1<<" marks for subject "<<j+ 1<<": ";
            cin>>smarks[j];
            tmarks+=smarks[j];
        }
        avgmarks=tmarks/3.0;
    }

    void disp() {
        cout<<"name: "<<name<<", roll no: "<<roll_no<<endl;
        cout<<"marks: ";
        for (int j = 0; j < 3; j++) {
            cout<<smarks[j]<<", ";
        }
        cout<<endl;
        cout<<"total Marks: "<<tmarks<<", average marks: "<<avgmarks<<endl<<endl;
    }

    float getavg() {
        return avgmarks;
    }
    int gettmarks() {
        return tmarks;
    }
    string getn() {
        return name;
    }
};

int main() {
    int n;
    cout<<"enter number of students: ";
    cin>>n;
    Student *students = new Student[n]; 

    for (int i=0; i<n; i++) {
        cout<<"enter details for student "<<i+1<<":"<<endl;
        students[i].input(i);
    }
    cout<<endl;
    cout<<"all students:"<<endl;
    for (int i=0; i<n; i++) {
        students[i].disp();
    }
    cout<<endl;
    cout<<"averages of students:"<<endl;
    for (int i=0; i<n; i++) {
        cout<<"student: "<<students[i].getn()<<", average Marks: "<<students[i].getavg()<<endl;
    }

    int highest = students[0].gettmarks();
    int x=0;

    for (int i=1; i<n; i++) {
        if (students[i].gettmarks() > highest) {
            highest= students[i].gettmarks();
            x=i;
        }
    }
    cout<<endl;
    cout<<"Student with highest total marks:"<<endl;
    cout<<"student: "<<students[x].getn()<<", total marks: "<< highest<<endl;
    delete[] students;
    students = NULL;

    return 0;
}

