#include <iostream>
using namespace std;

void arrayswap(int *ptr1, int *ptr2, int n);
void display(int *ptr1, int *ptr2, int n);

int main() {
    int n;
    do {
    cout<<"enter number of terms of arrays: ";
    cin>>n;
	} while(n<0);
    
    int arr1[n];
    int arr2[n];
    cout<<"enter "<<n<<" values in array 1: "<<endl;
    for (int i=0; i<n; i++) {
        cin>>arr1[i];
    }
    cout<<"enter "<<n<<" values in array 2: "<<endl;
    for (int i=0; i<n; i++) {
        cin>>arr2[i];
    }
    
    arrayswap(arr1, arr2, n);
    display(arr1, arr2, n);

    return 0;
}

void arrayswap(int *ptr1, int *ptr2, int n) {
    int temp;
    for (int i=0; i<n; i++) {
        temp=*ptr1;
        *ptr1=*ptr2;
        *ptr2=temp;
        ptr1++;
        ptr2++;
    }
}

void display(int *ptr1, int *ptr2, int n) {
    cout<<"Now values in array 1 are: "<<endl;
    for (int i=0; i<n; i++) {
        cout<<*ptr1;
        ptr1++;
    }
    cout<<endl;
    cout<<"Now values in array 2 are: "<<endl;
    for (int i=0; i<n; i++) {
        cout<<*ptr2;
        ptr2++;
    }
}
