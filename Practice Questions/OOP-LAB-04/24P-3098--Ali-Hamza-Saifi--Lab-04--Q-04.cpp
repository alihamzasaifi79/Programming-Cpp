#include <iostream>
using namespace std;

int main() {
    int r, c;

    cout<<"enter number of rows: ";
    cin>>r;
    cout<<"enter number of columns: ";
    cin>>c;

    int** mat=new int*[r];
    for(int i=0 ; i<r ; i++) {
        mat[i]=new int[c];
    }

    cout<<"enter elements of matrix:"<<endl;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            cin>>mat[i][j];
        }
    }

    int** tran=new int*[c];
    for(int i=0 ; i<c ; i++) {
        tran[i]=new int[r];
    }

    for(int i=0;i<r;i++) {
        for(int j=0 ; j<c ; j++) {
            tran[j][i]=mat[i][j];
        }
    }
    
    cout<<"original matrix:"<<endl;
    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            cout<<mat[i][j]<<"    ";
        }
        cout<<endl;
    }
    
    cout<<"transposed matrix:"<<endl;
    for(int i=0 ; i<c ; i++) {
        for(int j=0 ; j<r ; j++) {
            cout<<tran[i][j]<<"    ";
        }
        cout<<endl;
    }

    for(int i=0 ; i<r; i++) {
        delete[] mat[i];
        delete[] tran[i];
    }
    
    delete[] mat;
    delete[] tran;

    return 0;
}

