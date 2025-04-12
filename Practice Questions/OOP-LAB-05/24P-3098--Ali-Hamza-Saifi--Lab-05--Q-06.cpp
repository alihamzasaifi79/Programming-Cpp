#include<iostream>
using namespace std;

struct Company{
    string name;
    double revenue;
    struct Address{
        string city;
        int zip;
    } address;
};

void dispdetails(Company* companies,int n);

int main(){
    Company companies[3] = {
        {"Tech Sols", 250000, {"Lahore", 10000}},
        {"Global Sols", 450000, {"Islamabad", 10001}},
        {"Eco Sols", 12000, {"Karachi", 10002}}
    };
    
    dispdetails(companies, 3);
    
    return 0;
}

void dispdetails(Company* companies,int n){
    for(int i=0;i<n;i++){
        cout<<"company "<<i+1<<" details:"<<endl;
        cout<<"name: "<<companies[i].name<<endl;
        cout<<"revenue: $"<<companies[i].revenue<<endl;
        cout<<"city: "<<companies[i].address.city<<endl;
        cout<<"zip code: "<<companies[i].address.zip<<endl<<endl;
    }
}

