#include <iostream>
#include <string>
using namespace std;

struct doctor {
    string name;
    string specialization;
};

struct patient {
    string name;
    int age;
    doctor assigned_doctor;
};

struct hospital {
    string name;
    int total_patients;
    int capacity;
    patient* patients;
};

void resize_patients_array(hospital* h) {
    int new_capacity=h->capacity*2;
    patient* new_patients=new patient[new_capacity];
    for(int i=0;i<h->total_patients;i++) {
        new_patients[i]=h->patients[i];
    }
    delete[] h->patients;
    h->patients=new_patients;
    h->capacity=new_capacity;
}

void admit_patient(hospital* h) {
    if(h->total_patients==h->capacity) {
        resize_patients_array(h);
    }
    cout<<"\nEnter patient name: ";
    cin.ignore();
    getline(cin,h->patients[h->total_patients].name);
    cout<<"enter patient age: ";
    cin>>h->patients[h->total_patients].age;
    cin.ignore();
    cout<<"Enter doctor name: ";
    getline(cin,h->patients[h->total_patients].assigned_doctor.name);
    cout<<"Enter doctor's specialization: ";
    getline(cin,h->patients[h->total_patients].assigned_doctor.specialization);
    h->total_patients++;
    cout<<"patient admitted successfully!\n";
}

void display_patients(const hospital* h) {
    if(h->total_patients==0) {
        cout<<"No patients admitted yet.\n";
        return;
    }
    cout<<"\nHospital: "<<h->name<<"\nPatients List:\n";
    for(int i=0;i<h->total_patients;i++) {
        cout<<"\nPatient "<<i+1<<":\n";
        cout<<"Name: "<<h->patients[i].name<<"\n";
        cout<<"Age: "<<h->patients[i].age<<"\n";
        cout<<"Doctor: "<<h->patients[i].assigned_doctor.name<<"\n";
        cout<<"Specialization: "<<h->patients[i].assigned_doctor.specialization<<"\n";
    }
}

void discharge_patient(hospital* h,int index) {
    if(index<0||index>=h->total_patients) {
        cout<<"invalid patient index!\n";
        return;
    }
    for(int i=index;i<h->total_patients-1;i++) {
        h->patients[i]=h->patients[i+1];
    }
    h->total_patients--;
    cout<<"patient discharged successfully!\n";
}

int main() {
    hospital h;
    cout<<"enter hospital name: ";
    getline(cin,h.name);
    cout<<"enter initial capacity for patients: ";
    cin>>h.capacity;
    h.total_patients=0;
    h.patients=new patient[h.capacity];
    int choice;
    do {
        cout<<"\n1. admit Patient\n2. display patients\n3. discharge Patient\n4. Exit\nEnter choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                admit_patient(&h);
                break;
            case 2:
                display_patients(&h);
                break;
            case 3:
                int index;
                cout<<"enter patient index to discharge (1-based): ";
                cin>>index;
                discharge_patient(&h,index-1);
                break;
            case 4:
                cout<<"exiting...\n";
                break;
            default:
                cout<<"invalid choice!\n";
        }
    } while(choice!=4);
    delete[] h.patients;
    return 0;
}

