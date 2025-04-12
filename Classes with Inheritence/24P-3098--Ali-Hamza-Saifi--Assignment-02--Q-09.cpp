#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start_engine() {
        cout<<"vehicle engine started."<<endl;
    }
};

class Airplane: public Vehicle {
public:
    void start_engine() override {
        cout<<"airplane engine started."<<endl;
    }
};

int main() {
    Vehicle v;
    Airplane a;

    v.start_engine();
    a.start_engine();

    Vehicle* v_ptr = &a;
    v_ptr->start_engine();

    return 0;
}

