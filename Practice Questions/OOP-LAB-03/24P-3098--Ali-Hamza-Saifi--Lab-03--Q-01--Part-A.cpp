#include <iostream>
using namespace std;

int func(int size);

int main() {
    int size;
    cout<<"enter size of the arrays: ";
    cin>>size;
    
    cout<<func(size)<<" integer(s) are placed at same location with the same value in both arrays.";

    return 0;
}

int func(int size) {
    int* ptr1 = new int [size];
    int* ptr2 = new int [size];
    
    cout<<"enter "<<size<<" values in array 1: ";
    for (int i=0; i<size; i++) {
        cin>>ptr1[i];
    }
    
    cout<<"enter "<<size<<" values in array 2: ";
    for (int i=0; i<size; i++) {
        cin>>ptr2[i];
    }
    
    int count = 0;
    for (int i=0; i<size; i++) {
        if (ptr1[i] == ptr2[i]) {
            count++;
        }
    }
    
    delete[] ptr1;
    delete[] ptr2;
    ptr1 = NULL;
    ptr2 = NULL;
    return count;
}
