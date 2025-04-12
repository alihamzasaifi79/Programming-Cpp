#include <iostream>
using namespace std;

class Car {
    static int maxspeed;
    int curspeed;

public:
    void setspeed(int s) {
        curspeed=s;
        if(s>maxspeed){
            maxspeed=s;
        }
    }

    int getmax() {
        return maxspeed;
    }
};

int Car::maxspeed=0;

int main() {
    int w, x, y, z;
    cout<<"enter speed of car 1: ";
    cin>>w;
    cout<<"enter speed of car 2: ";
    cin>>x;
    cout<<"enter speed of car 3:";
    cin>>y;
    cout<<"enter speed of car 4:";
    cin>>z;
    Car c1,c2,c3,c4;
    c1.setspeed(w);
    c2.setspeed(x);
    c3.setspeed(y);
    c1.setspeed(z);
    cout<<"max speed: "<<c1.getmax();
}

