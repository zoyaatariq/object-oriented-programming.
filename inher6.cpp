#include <iostream>
using namespace std;

class Student {
protected:
    string name;
public:
    void getStudent() {
        cout << "Enter Student Name: ";
        cin >> name;
    }
};

class Sports : virtual public Student {
protected:
    int sportScore;
public:
    void getSport() {
        cout << "Enter Sports Score: ";
        cin >> sportScore;
    }
};

class Academics : virtual public Student {
protected:
    int academicScore;
public:
    void getAcademic() {
        cout << "Enter Academic Score: ";
        cin >> academicScore;
    }
};

class Result : public Sports, public Academics {
public:
    void display() {
        int finalScore = sportScore + academicScore;

        cout << "\n----- Final Result -----\n";
        cout << "Name: " << name << endl;
        cout << "Sports Score: " << sportScore << endl;
        cout << "Academic Score: " << academicScore << endl;
        cout << "Final Score: " << finalScore << endl;
    }
};

int main() {
    Result r;
    r.getStudent();
    r.getSport();
    r.getAcademic();
    r.display();
    return 0;
}
