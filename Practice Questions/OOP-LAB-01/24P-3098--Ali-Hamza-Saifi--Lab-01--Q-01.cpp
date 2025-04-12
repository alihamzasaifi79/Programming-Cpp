#include <iostream>
using namespace std;
void func(int arr[], int n);

int main() {
    int arr[25];
    func(arr, 25);

    return 0;
}

void func(int arr[], int n) {
	for (int i=0; i<25; i++) {
    	cout<<"enter number "<<i+1<<" from 10 to 100: ";
        cin>>arr[i];
        while (arr[i]<10 || arr[i]>100) {
            cout<<"enter this number again from 10 to 100: ";
            cin>>arr[i];
        }
        for (int j=0; j<i; j++) {
            if (arr[i] == arr[j]) {
                cout<<"number already exists, ";
                do {
                	cout<<"enter this number from 10 to 100: ";
                    cin>>arr[i];
                } while (arr[i]<10 || arr[i]>100);
                j=-1;
            }
        }
    }
    for (int i=0; i<25; i++) {
        cout<<arr[i]<<"\t";
    }
}
