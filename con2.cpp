// 2. Area & Perimeter of Rectangle (Constructor Overloading)
#include <iostream>
using namespace std;

class Rectangle {
    float l, w;
public:
    Rectangle(float x, float y) { l = x; w = y; }
    Rectangle(float x) { l = w = x; }
    float area() { return l * w; }
    float peri() { return 2 * (l + w); }
    void display() {
        cout << area() << " " << peri() << endl;
    }
};

int main() {
    Rectangle r1(5, 3);
    Rectangle r2(4);
    r1.display();
    r2.display();
    return 0;
}
