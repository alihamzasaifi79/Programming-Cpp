#include <iostream>
using namespace std;

class Rectangle {
public:
    int length;
    int breadth;

    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    Rectangle(Rectangle &r) {
        length = r.length;
        breadth = r.breadth;
    }
};

int main() {
	int l, w;
	cout<<"enter length and breadth: ";
	cin>>l>>w;
    Rectangle rect1(l, w);
    Rectangle rect2 = rect1;

    cout<<"rectangle 1 length: "<<rect1.length<<", breadth: "<<rect1.breadth<<endl;
    cout<<"rectangle 2 length: "<<rect2.length<<", breadth: "<<rect2.breadth<<endl;

    return 0;
}

