#include <iostream>
using namespace std;

void addition(int rows, int columns);

int main() {
    int rows, columns;
    cout<<"enter number of rows: ";
    cin>>rows;
    cout<<"enter number of columns: ";
    cin>>columns;
    
    addition(rows, columns);

    return 0;
}

void addition(int rows, int columns) {
    int** matA = new int* [rows];
    for (int i=0; i<rows; i++) {
        matA[i] = new int [columns];
    }
    
    int** matB = new int* [rows];
    for (int i=0; i<rows; i++) {
        matB[i] = new int [columns];
    }
    
    int** result = new int* [rows];
    for (int i=0; i<rows; i++) {
        result[i] = new int [columns];
    }
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout<<"enter row "<<i+1<<" column "<<j+1<<" value in first matrix"<<endl;
            cin>>matA[i][j];
        }
    }
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout<<"enter row "<<i+1<<" column "<<j+1<<" value in second matrix"<<endl;
            cin>>matB[i][j];
        }
    }
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
    
    cout<<"the resulttant matrix is: "<<endl;
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout<<result[i][j]<<"  ";
        }
        cout<<endl;
    }
}
