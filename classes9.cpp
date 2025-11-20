// 9. Electricity Bill Calculator
#include <iostream>
using namespace std;

class ElectricityBill {
    string name;
    float units, charge;
public:
    void input() {
        cin >> name >> units >> charge;
    }
    float bill() {
        return units * charge;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Total Bill: " << bill();
    }
};

int main() {
    ElectricityBill e;
    e.input();
    e.display();
    return 0;
}
