#include <iostream>
using namespace std;

class Employee {
private:
    const double salary;
    int emp_id;

public:
    Employee(int id) : salary(5000.0) {
        emp_id = id;
        cout<<"employee ID: "<<emp_id<<", salary: "<<salary<<", address: "<<this<<endl;
    }
};

int main() {
    Employee emp1(101);
    Employee emp2(102);

    return 0;
}

