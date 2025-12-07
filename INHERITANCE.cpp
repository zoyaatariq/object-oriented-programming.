#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int roll;
public:
    void getStudent() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> roll;
    }
};

class Marks : public Student {
    int m1, m2, m3;
public:
    void getMarks() {
        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }

    void displayReport() {
        int total = m1 + m2 + m3;
        float percent = total / 3.0;

        cout << "\n----- Academic Report -----\n";
        cout << "Name: " << name << "\nRoll: " << roll << endl;
        cout << "Total: " << total << "\nPercentage: " << percent << "%\n";
    }
};

int main() {
    Marks m;
    m.getStudent();
    m.getMarks();
    m.displayReport();
    return 0;
}
