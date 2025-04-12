#include <iostream>
using namespace std;

void reverse(int size);

int main() {
    int size;
    cout<<"enter size of the array: ";
    cin>>size;
    reverse(size);

    return 0;
}

void reverse(int size) {
	int* ptr = new int [size];
    
    cout<<"enter "<<size<<" values in the array: ";
    for (int i=0; i<size; i++) {
        cin>>ptr[i];
    }
    
    int start = 0, end = size -1;
    int temp;
    while (start < end) {
        temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;
        start++;
        end--;
    }
    cout<<"Reversed array is: "<<endl;
    for (int i=0; i<size; i++) {
        cout<<ptr[i]<<"     ";
    }
}
