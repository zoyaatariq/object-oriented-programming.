// 7. Distance Conversion
#include <iostream>
using namespace std;

class Distance {
    float meters;
public:
    void input() {
        cin >> meters;
    }
    void display() {
        cout << "Kilometers: " << meters / 1000 << endl;
        cout << "Centimeters: " << meters * 100 << endl;
        cout << "Millimeters: " << meters * 1000;
    }
};

int main() {
    Distance d;
    d.input();
    d.display();
    return 0;
}
