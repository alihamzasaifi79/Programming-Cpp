#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char *str1 = new char[100];
    char *str2 = new char[100];

    cout<<"Enter string 1: ";
    cin.getline(str1, 100);
    cout<<"Enter string 2: ";
    cin.getline(str2, 100);

    int l1 = strlen(str1);
    int l2 = strlen(str2);

    if (l1!=l2) {
        cout<<"strings are not reverse of each other"<<endl;
    }
	else {
        int flag = 1;
        for (int i=0; i<l1; i++) {
            if (str1[i]!=str2[l1-1-i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout<<"strings are reverse of each other"<<endl;
        } else {
            cout<<"strings are not reverse of each other"<<endl;
        }
    }

    delete[] str1;
    str1 = NULL;
    delete[] str2;
    str2 = NULL;

    return 0;
}

