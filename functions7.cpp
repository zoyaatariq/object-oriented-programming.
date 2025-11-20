#include <iostream>
using namespace std;

int main() {
    double t;
    int ch;
    cin >> t >> ch;

    if (ch == 1) {
        cout << (t * 9/5) + 32 << endl;
        cout << t + 273.15 << endl;
    } else if (ch == 2) {
        cout << (t - 32) * 5/9 << endl;
        cout << ((t - 32) * 5/9) + 273.15 << endl;
    } else if (ch == 3) {
        cout << t - 273.15 << endl;
        cout << ((t - 273.15) * 9/5) + 32 << endl;
    }

    return 0;
}
