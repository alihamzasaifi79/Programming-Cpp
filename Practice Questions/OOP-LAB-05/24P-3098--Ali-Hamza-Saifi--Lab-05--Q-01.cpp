#include <iostream>
using namespace std;

struct Rectangle{
    float len;
    float wid;
};

float cal(const Rectangle r){
    return r.len*r.wid;
}

int main(){
    Rectangle rect;
    cout<<"enter length of rectangle: ";
    cin>>rect.len;
    cout<<"enter width of rectangle: ";
    cin>>rect.wid;
    float area=cal(rect);
    cout<<"area of rectangle is: "<<area<<endl;
    return 0;
}

