// 5. Distance Addition (Meters & Centimeters)
#include <iostream>
using namespace std;

class Distance {
    int m, cm;
public:
    Distance(int x) { m = x; cm = 0; }
    Distance(int x, int y) { m = x; cm = y; }
    Distance add(Distance d) {
        Distance temp(0, 0);
        temp.cm = cm + d.cm;
        temp.m = m + d.m + temp.cm / 100;
        temp.cm = temp.cm % 100;
        return temp;
    }
    void display() {
        cout << m << "m " << cm << "cm";
    }
};

int main() {
    Distance d1(5, 80);
    Distance d2(3, 50);
    Distance d3 = d1.add(d2);
    d3.display();
    return 0;
}
