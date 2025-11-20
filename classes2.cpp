// 2. Circle Calculations
#include <iostream>
using namespace std;

class Circle {
    float radius;
public:
    void input() {
        cin >> radius;
    }
    float area() {
        return 3.14 * radius * radius;
    }
    float circumference() {
        return 2 * 3.14 * radius;
    }
    void display() {
        cout << "Area: " << area() << endl;
        cout << "Circumference: " << circumference() << endl;
    }
};

int main() {
    Circle c;
    c.input();
    c.display();
    return 0;
}
