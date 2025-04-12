#include <iostream>

using namespace std;

void rev(int * ptr, int n);
int sec(int * ptr, int n);
void rot(int * ptr, int n);

int main() {
    int n;
    cout << "enter number of values of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "enter value " << i + 1 << " in the array: ";
        cin >> arr[i];
    }

    int * ptr = arr;

    int choice;
    while (1) {
        cout << endl << endl;
        cout << "1. Reverse Array: " << endl;
        cout << "2. Second Largest: " << endl;
        cout << "3. Rotate Array: " << endl;
        cout << "4. Exit" << endl;
        cout << endl << endl;
        cout << "enter your choice: ";
        cin >> choice;
        int s;
        switch (choice) {
        case 1:
            rev(ptr, n);
            cout << "values in the array are: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << ",    ";
            }
            cout << endl << endl << endl;
            break;
        case 2:
            s = sec(ptr, n);
            if (s == -1000000)
                cout << "All numbers are equal, no second largest found" << endl;

            else
                cout << "second largest number is: " << s << endl;

            break;
        case 3:
            rot(ptr, n);
            cout << "After rotation: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << ",    ";
            }
            cout << endl << endl << endl;
            break;
        case 4:
            cout << "exiting..." << endl;
            exit(0);
        default:
            cout << "no valid choice" << endl;
            cout << endl << endl;
        }
    }

    return 0;
}

void rev(int * ptr, int n) {
    int temp;
    int i = 0;
    while (i < n / 2) {
        temp = * (ptr + i);
        *(ptr + i) = * (ptr + n - i - 1);
        *(ptr + n - i - 1) = temp;
        i++;
    }
}

int sec(int * ptr, int n) {
    int lar = * ptr;
    int slar = -10000000;
    int x = * ptr, xcounter = 0;
    for (int i = 0; i < n; i++) {
        if (x == * (ptr + i)) {
            xcounter++;
        }
    }
    if (xcounter == n) {
        return -1000000;
    } else {
        int i = 0;
        while (i < n) {
            if ( * (ptr + i) > lar) {
                slar = lar;
                lar = * (ptr + i);
            } else if ( * (ptr + i) < lar && * (ptr + i) > slar) {
                slar = * (ptr + i);
            }
            i++;
        }
    }
    return slar;
}

void rot(int * ptr, int n) {
    int k;
    cout << "enter number of positions to rotate: ";
    cin >> k;
    if (k <= 0) {
        cout << "you entered invalid number of position" << endl;
    } else {
        int temp;
        for (int j = 0; j < k; j++) {
            for (int i = n - 1; i > 0; i--) {
                temp = * (ptr + i);
                *(ptr + i) = * (ptr + i - 1);
                *(ptr + i - 1) = temp;
            }
        }
    }
}
