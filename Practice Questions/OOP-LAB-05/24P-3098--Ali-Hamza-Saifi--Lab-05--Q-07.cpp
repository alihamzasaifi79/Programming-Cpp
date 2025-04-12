#include<iostream>
using namespace std;

struct Car{
    string brand;
    int year;
    float price;
};
void upprice(Car* c, float discount);

int main(){
    Car car;
    cout<<"enter car brand: ";
    getline(cin, car.brand);
    cout<<"enter car year: ";
    cin>>car.year;
    cout<<"enter car price (in PKR): ";
    cin>>car.price;

    float discount;
    cout<<"enter discount percentage: ";
    cin>>discount;
    upprice(&car, discount);
    cout<<"updated price of car (in PKR): "<<car.price<<endl;

    return 0;
}

void upprice(Car* c, float discount){
    c->price = c->price - (c->price*discount/100);
}

