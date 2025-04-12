#include <iostream>
using namespace std;

struct Student {
    char name[50];
    int numSub;
    float *ptr;
    float avg;
};

float calc(Student s) {
    float avg = 0;
    for(int i=0; i<s.numSub; i++) {
        avg += s.ptr[i];
    }
    avg = avg/s.numSub;
    return avg;
}

void sort(Student *ptr, int n) {
    Student temp;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if(ptr[i].avg< ptr[j].avg) {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout<<"enter number of students: ";
    cin>>n;
    Student arr[n];
    for (int i=0; i<n; i++) {
        cout<<"enter name of student "<<i+1<<": ";
        cin.ignore();
        cin.getline(arr[i].name, 50);
        cout<<"enter number of subjects for student "<<i+1<<": ";
        cin>>arr[i].numSub;
        arr[i].ptr = new float [arr[i].numSub];
        for (int j=0; j<arr[i].numSub; j++) {
            cout<<"enter marks for student "<<i+1<<" subject "<<j+1<<": ";
        cin>>arr[i].ptr[j];
        }
        arr[i].avg = calc(arr[i]);
    }
    cout<<"before sorting: "<<endl<<endl;
        for (int i=0; i<n; i++) {
        cout<<"name of student "<<i+1<<": "<<arr[i].name<<endl;
    	cout<<"average of student "<<i+1<<" is: "<<arr[i].avg<<endl;
    }
    cout<<endl;
    sort(arr, n);
    cout<<"after sorting: "<<endl<<endl;
        for (int i=0; i<n; i++) {
            cout<<"name of student "<<i+1<<": "<<arr[i].name<<endl;
            cout<<"average of student "<<i+1<<" is: "<<arr[i].avg<<endl;
        }
        
        cout<<"highest average score student is: "<<endl<<endl;
        cout<<"Name: "<<arr[0].name<<endl;
        cout<<"Average: "<<arr[0].avg<<endl;
        
        for (int i=0; i<n; i++) {
            delete[] arr[i].ptr;
            arr[i].ptr = NULL;
        }

    return 0;
}
