#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

void trans(Point* p, int dx, int dy) {
    p->x +=dx;
    p->y +=dy;
}

void dis(Point* p, int n) {
    for (int i = 0; i < n; i++) {
        cout<<"point "<<i+1<<": ("<<p[i].x<<", "<<p[i].y<<")"<< endl;
    }
}

int main() {
    int n, dx, dy;
    cout<<"enter number of points: ";
    cin>>n;
    
    Point *ptr = new Point[n];
    
    for (int i =0; i<n; i++) {
        cout<<"enter x for point "<<i+1<<": ";
        cin>>ptr[i].x;
        cout<<"enter y for point "<<i+1<<": ";
        cin>>ptr[i].y;
    }
    
    cout<<"points before translation: "<<endl;
    dis(ptr, n);
    
    cout<<"enter dx for translation: ";
    cin>>dx;
    
    cout<<"enter dy for translation: ";
    cin>>dy;
    
    for (int i = 0; i < n; i++) {
        trans(&ptr[i], dx, dy);
    }
    cout<<endl;
    cout << "Points after translation:"<<endl;
    dis(ptr, n);

    delete[] ptr;

    return 0;
}
