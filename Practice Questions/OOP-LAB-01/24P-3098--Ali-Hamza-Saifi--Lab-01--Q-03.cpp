#include <iostream>
using namespace std;

float rentcalc (int days, int miles);

int main() {
    int days, miles;
    do {
	    cout<<"enter number of days: ";
	    cin>>days;
	} while (days<0);
	do {
	    cout<<"enter miles travelled: ";
	    cin>>miles;
	} while (miles<0);
    cout<<rentcalc(days, miles);

    return 0;
}

float rentcalc (int days, int miles) {
    float rent;
    if (days>30) {
        rent = (days * 25) + (0.15 * miles);
        rent = rent - (rent * 0.2);
    }
    else if (days<15) {
        rent = (days * 26.99) + (0.15 * miles); 
    }
    else {
        rent = (days * 25) + (0.15 * miles);
    }
    return rent;
}
