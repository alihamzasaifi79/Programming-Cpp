#include <iostream>

using namespace std;

int rec(int arr[], int n);
int fact(int n);

int main() {
    int n;
    cout << "enter number of values of array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "enter value " << i + 1 << " in the array: ";
        cin >> arr[i];
    }
    cout << endl << endl;
    cout << "sum of array values is: " << rec(arr, n - 1) << endl;
    cout << "factorial of the number is: " << fact(n) << endl;

    return 0;
}

int rec(int arr[], int n) {
    if (n < 0) {
        return 0;
    }

    return arr[n] + rec(arr, n - 1);
}

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}
