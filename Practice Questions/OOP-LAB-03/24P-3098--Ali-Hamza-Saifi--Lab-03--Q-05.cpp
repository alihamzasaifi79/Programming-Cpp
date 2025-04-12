#include <iostream>
using namespace std;

void xarray(int* ptr, int size);

int main() {
    int size;
    cout<<"enter size of the array: ";
    cin>>size;
    int* ptr = new int[size];
    
    cout<<"enter "<<size<<" values in the array: ";
    for (int i=0; i<size; i++) {
        cin>>ptr[i];
    }
    
    xarray(ptr, size);

    return 0;
}

void xarray(int* ptr, int size) {
    int newsize;
    cout<<"enter size of the new array: ";
    cin>>newsize;
    if(newsize>size) {
        int* newarray = new int [newsize];
        
        for (int i=0; i<size; i++) {
            newarray[i] = ptr[i];
        }
        cout<<"you have "<<newsize - size<<" values to put in new array: "<<endl;
        cout<<"put these values"<<endl;
        for (int i=size; i<newsize; i++) {
            cin>>newarray[i];
        }
        for (int i=0; i<newsize; i++) {
            cout<<newarray[i]<<"    ";
        }
    }
    else {
        cout<<"new array size must be greater than the first one";
    }
}
