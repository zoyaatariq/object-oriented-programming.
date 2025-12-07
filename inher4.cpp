#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
};

class Circle : public Shape {
    float r;
public:
    void area() {
        cout << "Enter radius: ";
        cin >> r;
        cout << "Area of Circle: " << 3.14f * r * r << endl;
    }
};

class Rectangle : public Shape {
    float l, b;
public:
    void area() {
        cout << "Enter length and breadth: ";
        cin >> l >> b;
        cout << "Area of Rectangle: " << l * b << endl;
    }
};

class Triangle : public Shape {
    float b, h;
public:
    void area() {
        cout << "Enter base and height: ";
        cin >> b >> h;
        cout << "Area of Triangle: " << 0.5f * b * h << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;
    Triangle t;

    c.area();
    r.area();
    t.area();

    return 0;
}
