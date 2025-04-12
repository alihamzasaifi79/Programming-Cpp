#include<iostream>
using namespace std;

struct Hospital{
    string name;
    struct Doctor{
        string name;
        string spec;
    } doc[3];
};

void dispdetails(Hospital* hospitals, int n);

int main(){
    int n;
    cout<<"enter number of hospitals: ";
    cin>>n;
    cin.ignore();

    Hospital* hospitals = new Hospital[n];

    for(int i=0;i<n;i++){
        cout<<"enter details for hospital "<<i+1<<":"<<endl;
        cout<<"hospital name: ";
        getline(cin,hospitals[i].name);

        for(int j=0;j<3;j++){
            cout<<"enter details for doctor "<<j+1<<" at "<<hospitals[i].name<<":"<<endl;
            cout<<"doctor name: ";
            getline(cin,hospitals[i].doc[j].name);
            cout<<"specialization: ";
            getline(cin,hospitals[i].doc[j].spec);
        }
    }

    dispdetails(hospitals,n);

    delete[] hospitals;
    hospitals = NULL;

    return 0;
}

void dispdetails(Hospital* hospitals,int n){
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<"hospital "<<i+1<<" details:"<<endl;
        cout<<"hospital name: "<<hospitals[i].name<<endl;

        for(int j=0;j<3;j++){
            cout<<"doctor "<<j+1<<" name: "<<hospitals[i].doc[j].name<<endl;
            cout<<"specialization: "<<hospitals[i].doc[j].spec<<endl;
        }
    }
}

