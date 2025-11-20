// 8. Speed Calculator (Distance/Time)
#include <iostream>
using namespace std;

class Speed {
    float d, t;
public:
    Speed(float a, float b) { d = a; t = b; }
    void display() {
        cout << d / t;
    }
};

int main() {
    Speed s(100, 2);
    s.display();
    return 0;
}
