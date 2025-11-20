// 4. Temperature Conversion
#include <iostream>
using namespace std;

class Temperature {
    float temp;
public:
    void cToF() {
        cin >> temp;
        cout << "Fahrenheit: " << (temp * 9/5) + 32;
    }
    void fToC() {
        cin >> temp;
        cout << "Celsius: " << (temp - 32) * 5/9;
    }
};

int main() {
    Temperature t;
    int ch;
    cin >> ch;
    if(ch == 1) t.cToF();
    else t.fToC();
    return 0;
}
