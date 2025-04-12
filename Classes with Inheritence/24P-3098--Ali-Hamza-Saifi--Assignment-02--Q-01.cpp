#include <iostream>
using namespace std;

class Employee {
public:
	Employee() {
		add_employee();
	}
    static int emp_count;

    static void add_employee() {
        emp_count++;
        cout<<"total number of employees: "<<emp_count<<endl;
    }
};

int Employee::emp_count=0;

int main() {
	Employee emp1;
	Employee emp2;

    return 0;
}

