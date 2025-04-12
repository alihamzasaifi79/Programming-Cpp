#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout<<"enter number of rows and columns for matrix 1: ";
    cin>>r1>>c1;
    cout<<"enter number of rows and columns for matrix 2: ";
    cin>>r2>>c2;

    if (c1!=r2) {
        cout<<"matrices cannot be multiplied Number of columns in 1 must be equal to number of rows in 2."<<endl;
        return 0;
    }
    
    int** matA = new int*[r1];
    for (int i=0; i<r1; i++) {
        matA[i] = new int[c1];
    }
    int** matB = new int*[r2];
    for (int i=0; i<r2; i++) {
        matB[i] = new int[c2];
    }
    int** matC = new int*[r1];
    for(int i=0; i<r1; i++) {
        matC[i] = new int[c2];
    }
    cout<<"enter elements of matrix 1:"<<endl;
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            cin>>matA[i][j];
        }
    }
    cout<<"enter elements of matrix 2:"<<endl;
    for(int i=0; i<r2; i++) {
        for (int j=0; j<c2; j++) {
            cin>>matB[i][j];
        }
    }
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            matC[i][j] = 0;
            for (int k=0; k<c1; k++) {
                matC[i][j] += matA[i][k]*matB[k][j];
            }
        }
    }
    cout<<"matrix C:"<<endl;
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            cout<<matC[i][j]<<"    ";
        }
        cout<<endl;
    }
    for (int i=0; i<r1; i++) {
        delete[] matA[i];
    }
    delete[] matA;
    matA = NULL;

    for (int i=0; i<r2; i++) {
        delete[] matB[i];
    }
    delete[] matB;
    matB = NULL;

    for (int i=0; i<r1; i++) {
        delete[] matC[i];
    }
    delete[] matC;
    matC = NULL;

    return 0;
}

