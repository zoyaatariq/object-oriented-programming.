#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    float basic;
public:
    void getEmployee() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Basic Salary: ";
        cin >> basic;
    }
};

class Salary : public Employee {
public:
    void generateSlip() {
        float hra = basic * 0.20;
        float da  = basic * 0.10;
        float pf  = basic * 0.05;

        float gross = basic + hra + da;
        float net = gross - pf;

        cout << "\n----- Salary Slip -----\n";
        cout << "Name: " << name << "\nID: " << id << endl;
        cout << "Basic: " << basic << endl;
        cout << "HRA: " << hra << "\nDA: " << da << "\nPF: " << pf << endl;
        cout << "Net Salary: " << net << endl;
    }
};

int main() {
    Salary s;
    s.getEmployee();
    s.generateSlip();
    return 0;
}
