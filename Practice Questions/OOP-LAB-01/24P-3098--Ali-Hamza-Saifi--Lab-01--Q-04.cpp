#include <iostream>
#include <string>
using namespace std;

void studentData(string name[], int roll_no[], float marks[][3], float totalMarks[], float avg[], int n, int *ptr);
void display_std(string name[], int roll_no[], float marks[][3], float totalMarks[], float avg[], int n);
void highest(string name[], int roll_no[], float totalMarks[], float avg[], int n);
void display_avg(string name[], int roll_no[], float avg[], int n);
void class_avg(float avg[], int n);

int main() {
	int count = 0;
	string name[10];
    int roll_no[10];
    float marks[10][3];
    float totalMarks[10];
    float avg[10];
    while(1) {
    	cout<<endl;
    	cout<<"-------------------------------------------------------------------------------"<<endl;
	    cout<<"1. Add Student"<<endl;
		cout<<"2. Display Students"<<endl; 
		cout<<"3. Find Topper"<<endl;
		cout<<"4. Display Averages"<<endl;
		cout<<"5. Class Average"<<endl;
		cout<<"6. exit..."<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		int choice;
		cout<<"enter your choice: ";
		if (cin>>choice) {
			switch(choice) {
				case 1:
					studentData(name, roll_no, marks, totalMarks, avg, count, &count);
					break;
				case 2:
					display_std(name, roll_no, marks, totalMarks, avg, count);
					break;
				case 3:
					highest(name, roll_no, totalMarks, avg, count);
					break;
				case 4:
					display_avg(name, roll_no, avg, count);
					break;
				case 5:
					class_avg(avg, count);
					break;
				case 6:
					cout<<"Program exiting..."<<endl;
					cout<<"Good Bye";
					exit(1);
			default:
					cout<<"Invalid Input, please enter from 1 to 6 only";
		}
	}
	else {
		cout << "Invalid input. Please enter a number"<<endl;
		cin.clear();
		cin.ignore();
	}
	}
    
    return 0;
}

void studentData(string name[], int roll_no[], float marks[][3], float totalMarks[], float avg[], int n, int *ptr) {
	float sum = 0.0;
	if (n==10) {
		cout<<"Maximum numbers of students already added, Thank You";
	}
	else {
		cout<<"enter student "<<n+1<<" name : ";
		cin.ignore();
		getline(cin, name[n]);
		roll_no[n] = n+1;
		do {
			cout<<"enter student "<<n+1 <<" marks in first subjects (out of 100): ";
			cin>>marks[n][0];
		} while(marks[n][0]<0 || marks[n][0]>100);
		sum += marks[n][0];
		do {
			cout<<"enter student "<<n+1 <<" marks in second subjects (out of 100): ";
			cin>>marks[n][1];
		} while(marks[n][1]<0 || marks[n][1]>100);
		sum += marks[n][1];
		do {
			cout<<"enter student "<<n+1 <<" marks in third subjects (out of 100): ";
			cin>>marks[n][2];
		} while(marks[n][2]<0 || marks[n][2]>100);
		sum += marks[n][2];
	}
	totalMarks[n] = sum;
	avg[n] = sum/3.0;
	(*ptr)++;
	
}

void display_std(string name[], int roll_no[], float marks[][3], float totalMarks[], float avg[], int n) {
	if (n==0) {
		cout<<"Student data not found";
	}
	else {
		cout<<endl;
		cout<<"-------------------------------------------";
		for (int i=0; i<n; i++) {
			cout<<"Student Name: "<<name[i]<<endl;
			cout<<"Roll No: "<<roll_no[i]<<endl;
			cout<<"Sub_1 Marks: "<<marks[i][0]<<endl;
			cout<<"Sub_2 Marks: "<<marks[i][1]<<endl;
			cout<<"Sub_2 Marks: "<<marks[i][2]<<endl;
			cout<<"Total Marks: "<<totalMarks[i]<<endl;
			cout<<"Average (3 subjects): "<<avg[i]<<endl;
			cout<<"-------------------------------------------";
			cout<<endl<<endl<<endl;
		}
	}
}

void highest(string name[], int roll_no[], float totalMarks[], float avg[], int n) {
	int highest=0, count=0;
	if (n==0) {
		cout<<"No Student Data found";
	}
	else {
		for (int i=0; i<n; i++) {
			if (highest <= totalMarks[i]) {
				highest=totalMarks[i];
			}
		}
		for (int i=0; i<n; i++) {
			if (highest==totalMarks[i]) {
				count++;
			}
		}
		cout<<endl<<endl;
		cout<<count<<" Students got highest marks: ";
		cout<<endl<<endl;
		for (int i=0; i<n; i++) {
			if(highest==totalMarks[i]) {
				cout<<"Name: "<<name[i]<<"          "<<"Roll No. "<<roll_no[i]<<"          "<<"Marks: "<<totalMarks[i]<<"          "<<"Average: "<<avg[i]<<endl;
			}
		}
	}
}

void display_avg(string name[], int roll_no[], float avg[], int n) {
	if (n==0) {
		cout<<"No Student Data Found";
	}
	else {
		cout<<endl<<"Student Averages";
		cout<<endl<<endl;
		for (int i=0; i<n; i++) {
			cout<<"Name: "<<name[i]<<"        Roll No. "<<roll_no[i]<<"        Average: "<<avg[i]<<endl;
		}
	}
}

void class_avg(float avg[], int n) {
	if (n==0) {
		cout<<"No Student Data Found";
	}
	else {
		float class_average = 0;
		for (int i=0; i<n; i++) {
			class_average += avg[i];
		}
		class_average /= n;
		cout<<"Class Average is: "<<class_average;
	}
}
