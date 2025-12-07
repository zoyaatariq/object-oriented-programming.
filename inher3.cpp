#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void getPerson() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }
};

class Student : public Person {
protected:
    int roll;
public:
    void getStudent() {
        cout << "Enter Roll Number: ";
        cin >> roll;
    }
};

class Result : public Student {
    int m1, m2, m3;
public:
    void getMarks() {
        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }

    void display() {
        int total = m1 + m2 + m3;
        float percent = total / 3.0;

        cout << "\n----- Result Summary -----\n";
        cout << "Name: " << name << "\nAge: " << age << endl;
        cout << "Roll: " << roll << endl;
        cout << "Total: " << total << "\nPercentage: " << percent << "%\n";
    }
};

int main() {
    Result r;
    r.getPerson();
    r.getStudent();
    r.getMarks();
    r.display();
    return 0;
}
