#include<iostream>
using namespace std;

class Shape{
private:
    double area;
protected:
    virtual void calc_area(double a) {
    	area = a;
	};
public:
    void display_area(){
        cout<<"area: "<<area<<endl;
    }
};

class Circle: public Shape{
private:
    double radius;
public:
    Circle(double r){
        radius = r;
        calc_area(3.14*radius*radius);
    }
    void calc_area(double a) override{
        Shape::calc_area(a);
    }
};

int main(){
	double r;
	cout<<"enter radius: ";
	cin>>r;
    Circle c(r);
    c.display_area();
    return 0;
}

