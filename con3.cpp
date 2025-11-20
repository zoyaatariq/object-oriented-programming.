// 3. Temperature Conversion (Celsius → Fahrenheit)
#include <iostream>
using namespace std;

class Temperature {
    float c;
public:
    Temperature(float x) { c = x; }
    void display() {
        float f = (c * 9/5) + 32;
        cout << c << " " << f;
    }
};

int main() {
    Temperature t(25);
    t.display();
    return 0;
}
