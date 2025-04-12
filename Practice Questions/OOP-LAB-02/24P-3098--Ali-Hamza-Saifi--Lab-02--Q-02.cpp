#include <iostream>
#include <string>
using namespace std;

void are_rev(string str1, string str2);

int main() {
	string str1, str2;
	cout<<"enter string 1: ";
	getline(cin, str1);
	cout<<"enter string 2: ";
	getline(cin, str2);
	are_rev(str1, str2);
	
	return 0;
}

void are_rev(string str1, string str2) {
	int counter1 = 0, counter2 = 0, i = 0;
	
	while(str1[i]) {
		counter1++;
		i++;
	}
	i = 0;
	
	while(str2[i]) {
		counter2++;
		i++;
	}
	i = 0;
	
	if(counter1 == 0 && counter2 == 0) {
    	cout << "both strings are empty"<<endl;
    	return;
	}
	else if (counter1 == 0 || counter2 == 0) {
    	cout << "one of the strings is empty"<<endl;
    	return;
	}

	if(counter1 != counter2) {
		cout<<"string 1 and string 2 are not reverse each other"<<endl;
	}
	else{
		char temp;
		counter2 -= 1;
		while(counter2 > i) {
			temp = str2[counter2];
			str2[counter2] = str2[i];
			str2[i] = temp;
			counter2--;
			i++;
		}
		i = 0;
		
		while(str1[i]) {
			if(str1[i] != str2[i]) {
				cout<<"string 1 and string 2 are not reverse of each other"<<endl;
				return;
			}
			i++;
		}
		
		cout<<"string 1 and string 2 are reverse of each other"<<endl;
	}
}
