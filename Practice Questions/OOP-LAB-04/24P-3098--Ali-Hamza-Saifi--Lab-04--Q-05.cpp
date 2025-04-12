#include <iostream>
using namespace std;

int main() {
    int **seats;
    int r = 0;
    int row, col;

    seats = new int*[10];
    for (int i=0; i<10; i++) {
        seats[i] = new int[10];
        for (int j=0; j<10; j++) {
            seats[i][j] = 0;
        }
    }

    while (1) {
        cout<<"enter row (1-10) and column (1-10) to reserve or 0 0 to stop: ";
        cin>>row>>col;

        if (row==0 && col==0) {
            break;
        }

        if (row<1 || row>10 || col<1 || col>10) {
            cout<<"invalid input enter row and column between 1 and 10"<<endl;
            continue;
        }

        row--;
        col--;

        if (seats[row][col]==0) {
            seats[row][col]=1;
            r++;
            cout<<"seat reserved"<<endl;
        }
        else {
            cout<<"seat already reserved"<<endl;
        }
    }

    cout<<"total reserved seats: "<<r<<endl;

    for (int i=0; i<10; i++) {
        delete[] seats[i];
    }
    delete[] seats;
    seats = NULL;

    return 0;
}

