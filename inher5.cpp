#include <iostream>
using namespace std;

class Teacher {
protected:
    string tname;
public:
    void getTeacher() {
        cout << "Enter Teacher Name: ";
        cin >> tname;
    }
};

class Researcher {
protected:
    string topic;
public:
    void getResearch() {
        cout << "Enter Research Topic: ";
        cin >> topic;
    }
};

class Faculty : public Teacher, public Researcher {
public:
    void showProfile() {
        cout << "\n----- Faculty Profile -----\n";
        cout << "Teacher Name: " << tname << endl;
        cout << "Research Topic: " << topic << endl;
    }
};

int main() {
    Faculty f;
    f.getTeacher();
    f.getResearch();
    f.showProfile();
    return 0;
}
