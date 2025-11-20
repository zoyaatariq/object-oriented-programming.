// 3. Simple Interest Calculator
#include <iostream>
using namespace std;

class Interest {
    float p, r, t;
public:
    void input() {
        cin >> p >> r >> t;
    }
    float simpleInterest() {
        return (p * r * t) / 100;
    }
    void display() {
        cout << "Simple Interest: " << simpleInterest();
    }
};

int main() {
    Interest i;
    i.input();
    i.display();
    return 0;
}
