// 6. Electricity Bill Calculator (Copy Constructor)
#include <iostream>
using namespace std;

class Bill {
    int units;
public:
    Bill(int u) { units = u; }
    Bill(Bill &b) { units = b.units; }
    int total() { return units * 5; }
    void display() {
        cout << total() << endl;
    }
};

int main() {
    Bill b1(100);
    Bill b2(b1);
    b1.display();
    b2.display();
    return 0;
}
