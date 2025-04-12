#include <iostream>
using namespace std;

class Car {
public:
    string model;
    int year;

    Car(string m, int y) {
    	cout<<"car (object) created with model and year: "<<m<<" "<<y<<endl;
        model = m;
        year = y;
    }

    ~Car() {
        cout<<"car model: "<<model<<" with year: "<<year<<" is destroyed"<<endl;
    }
};

int main() {
	string model;
	int year;
	cout<<"enter car's model: ";
	getline(cin, model);
	cout<<"enter year: ";
	cin>>year;
    Car car1(model, year);
    cin.ignore();
    cout<<"enter car's model: ";
	getline(cin, model);
	cout<<"enter year: ";
	cin>>year;
    Car car2(model, year);

    return 0;
}
