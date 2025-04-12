#include <iostream>
using namespace std;

void dis(int **ptr, int r, int c);
int diagsum(int **ptr, int m, int n);
int secdiagsum(int **ptr, int m, int n);
int absdif(int **ptr, int m, int n);

int main() {
	int m, n;
	cout<<"enter the rows of the matrix: ";
	cin>>m;
	cout<<"enter the columns of the matrix: ";
	cin>>n;
	
	if (m==1 && n==1) {
	    cout<<"(1 x 1) matrix not possible";
	}
	else if(m==n) {
	
    	int **ptr = new int*[m];
    	for (int i=0; i<m; i++) {
    	    ptr[i] = new int[n];
    	}
    	
    	cout<<"enter values in the 2d matrix: "<<endl<<endl;
    	
    	for (int i=0; i<m; i++) {
    	    for (int j=0; j<n; j++) {
    	        cout<<"enter value at row "<<i+1<<" and column "<<j+1<<": ";
    	        cin>>ptr[i][j];
    	    }
    	}
    	cout<<endl;
    	dis(ptr, m, n);
    	cout<<endl;
    	cout<<"sum of main diagnal elements are: "<<diagsum(ptr, m, n)<<endl<<endl;
    	
    	cout<<"sum of sec diagnal elements are: "<<secdiagsum(ptr, m, n)<<endl<<endl;
    	
    	cout<<"the absolute difference is: "<<absdif(ptr, m, n)<<endl;
    	
    	for(int i=0; i<m; i++) {
    		delete[] ptr[i];
		}
		delete ptr;
	}
	else {
	    cout<<"not a square matrix, For diagnols, square matrix is required";
	}

    return 0;
}


void dis(int **ptr, int r, int c) {
    cout<<"the matrix elements are: "<<endl;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout<<ptr[i][j]<<"    ";
        }
        cout<<endl;
    }
}

int diagsum(int **ptr, int m, int n) {
    int sum = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if(i==j) {
                sum += ptr[i][j];
            }
        }
    }
    return sum;
}

int secdiagsum(int **ptr, int m, int n) {
    int sum = 0;
    m--, n--;
    int i=0, j=n;
    while (i<=m) {
        sum += ptr[i][j];
        i++, j--; 
    }
    return sum;
}

int absdif(int **ptr, int m, int n) {
    int sum1 = diagsum(ptr, m, n);
    int sum2 = 0;
    m--, n--;
    int i=0, j=n;
    while (i<=m) {
        sum2 += ptr[i][j];
        i++, j--; 
    }
    int abs = sum1 - sum2;
    if(abs<0) {
        abs = -1 * abs;
    }
    return abs;
}
