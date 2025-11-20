// 1. Simple Interest Calculator (Parameterized Constructor)
#include <iostream>
using namespace std;

class Interest {
    float p, r, t;
public:
    Interest(float p1, float r1, float t1) {
        p = p1; r = r1; t = t1;
    }
    float calc() {
        return (p * r * t) / 100;
    }
    void display() {
        cout << calc();
    }
};

int main() {
    Interest I(1000, 5, 2);
    I.display();
    return 0;
}
