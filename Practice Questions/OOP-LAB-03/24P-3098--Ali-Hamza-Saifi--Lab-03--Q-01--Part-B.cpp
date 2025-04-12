#include <iostream>
using namespace std;

int common(int size);

int main() {
    int size;
    cout<<"enter size of the arrays: ";
    cin>>size;
    cout<<common(size)<<" elements are common"<<endl;

    return 0;
}

int common(int size) {
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
    
    for (int i = 0; i<size-1; i++) {
        for (int j = 0; j<size-1-i; j++) {
            if (ptr1[j]>ptr1[j+1]) {
                int temp=ptr1[j];
                ptr1[j]=ptr1[j+1];
                ptr1[j+1]=temp;
            }
        }
    }
    
    int count=0;
    for (int i=0;i<size;i++) {
        if (i<size-1) {
            if (ptr1[i]==ptr1[i+1]) {
                continue;
            }
        }

        for (int j=0;j<size;j++) {
            if (ptr2[j]==-100000) {
                continue;
            }
            if (ptr1[i]==ptr2[j]) {
                count++;
                ptr2[j]=-100000;
                break;
            }
        }
    }
    
    delete[] ptr1;
    ptr1=NULL;
    delete[] ptr2;
    ptr2=NULL;
    return count;
}

