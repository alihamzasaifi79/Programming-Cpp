#include <iostream>
using namespace std;

int fact(int n) {
    int fact = 1;
    for (int i=1; i<n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int m, n;
    
    cout<<"enter rows: ";
    cin>>m;
    cout<<"enter columns: ";
    cin>>n;
    
    int fmn = fact(m+n-1);
    int fm = fact(m);
    int fn = fact(n);
    
    int r = fmn/(fm*fn);
    cout<<"the number of unique paths: "<<r<<endl;
    
    return 0;
}

