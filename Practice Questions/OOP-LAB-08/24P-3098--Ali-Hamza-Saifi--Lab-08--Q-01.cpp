#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string address;

    Person(string n="", string a="") : name(n), address(a) {}

    void set_name(string n) {
        name=n;
    }
    
    string get_name() const {
        return name;
    }

    void set_add(string a) {
        address=a;
    }
    
    string get_add() const {
        return address;
    }
};

class Employee : public Person {
public:
    int emp_num;
    int hours_worked;

    Employee(string n="", string a="", int empNum=0, int hours=0) : Person(n, a), emp_num(empNum), hours_worked(hours) {}

    void set_emp_num(int enumb) {
        emp_num=enumb;
    }
    int get_emp_num() const {
        return emp_num;
    }

    void set_hours_worked(int hours) {
        hours_worked=hours;
    }
    
    int get_hours_worked() const {
        return hours_worked;
    }
};

class ProductionWorker : public Employee {
private:
    int shift;
    double hour_pay;
    double salary;

public:
    ProductionWorker(string n, string a, int empNum, int hours, int s, double rate) : Employee(n, a, empNum, hours), shift(s), hour_pay(rate), salary(0.0) {}

    void set_shift(int s) {
        shift=s;
    }
    
    int get_shift() const {
        return shift;
    }

    void set_hour_pay(double rate) {
        hour_pay=rate;
    }
    double get_hour_pay() const {
        return hour_pay;
    }

    double calculate_salary() {
        salary=hour_pay*hours_worked;
        if (shift==2 && hours_worked>5) {
            salary+=1000;
        }
        return salary;
    }

    void print_details() {
        cout<<"Employee Details:"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Employee Number: "<<emp_num<<endl;
        cout<<"Hours Worked: "<<hours_worked<<endl;
        cout<<"Shift: "<<(shift==1?"Day":"Night")<<endl;
        cout<<"Hourly Pay Rate: "<<hour_pay<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

int main() {
    ProductionWorker worker1("Ali", "123 Peshawar", 101, 6, 2, 20.0);
    worker1.calculate_salary();
    worker1.print_details();

    cout<<"---------------------------"<<endl;

    ProductionWorker worker2("Raza", "kohat", 102, 4, 1, 18.5);
    worker2.calculate_salary();
    worker2.print_details();

    return 0;
}
