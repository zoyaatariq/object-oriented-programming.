// 6. Average of Three Numbers
#include <iostream>
using namespace std;

class Average {
    int a, b, c;
public:
    void input() {
        cin >> a >> b >> c;
    }
    float calc() {
        return (a + b + c) / 3.0;
    }
    void display() {
        cout << "Average: " << calc();
    }
};

int main() {
    Average A;
    A.input();
    A.display();
    return 0;
}
