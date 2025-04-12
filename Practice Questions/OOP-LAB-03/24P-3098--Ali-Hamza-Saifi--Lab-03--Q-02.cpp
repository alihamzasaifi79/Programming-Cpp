#include <iostream>
using namespace std;

void swapping();

int main() {
	swapping();

    return 0;
}

void swapping() {
	int* ptr1 = new int;
    int* ptr2 = new int;
    
    cout<<"enter number 1: ";
    cin>>*ptr1;
    
    cout<<"enter number 2: ";
    cin>>*ptr2;
    
    cout<<"Before swapping: "<<endl;
    cout<<"Number 1: "<<*ptr1<<endl;
    cout<<"Number 2: "<<*ptr2<<endl;
    
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    cout<<endl<<endl;
    cout<<"After swapping: "<<endl;
    cout<<"Number 1: "<<*ptr1<<endl;
    cout<<"Number 2: "<<*ptr2<<endl;
    
    delete ptr1;
    ptr1 = NULL;
    
    delete ptr2;
    ptr2 = NULL;
}
