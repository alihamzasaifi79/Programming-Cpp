#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void crt_file(string file_name);
void wrt_file(string file_name);
void app_file(string file_name);

int main() {
    string file_name;
    cout<<"enter text file name: ";
    getline(cin, file_name);
    file_name += ".txt";
    crt_file(file_name);
    wrt_file(file_name);
    app_file(file_name);

    return 0;
}

void crt_file(string file_name) {
    ofstream outFile(file_name.c_str());
    if(outFile.is_open()) {
        cout<<"file created successfully!"<<endl;
    }
    else {
        cerr<<"failed to create the file"<<endl;
    }
    outFile.close();

}

void wrt_file(string file_name) {
	string name, roll_no, hobbies;
    ofstream outFile(file_name.c_str());
    if(outFile.is_open()) {
    	cout<<"enter name: ";
    	getline(cin, name);
    	cout<<"enter roll_no: ";
    	getline(cin, roll_no);
    	cout<<"enter your hobbies: ";
    	getline(cin, hobbies);
    	outFile<<"Name: "<<name<<endl;
    	outFile<<"Roll No: "<<roll_no<<endl;
    	outFile<<"Hobbies: "<<hobbies<<endl;
        outFile.close();
    }
    else {
        cerr<<"failed to open the file for writing";
    }
}

void app_file(string file_name) {
	int age;
	ofstream appFile(file_name.c_str(), std::ios::app);
	if(appFile.is_open()) {
		cout<<"enter age: ";
		cin>>age;
		appFile<<"Age: "<<age<<endl;
		appFile.close();
        cout<<"data written successfully!"<<endl;
	}
	else {
		cout<<"failed to open the file in the append mode"<<endl;
	}
}
