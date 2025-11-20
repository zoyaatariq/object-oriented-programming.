
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

bool checkIntOverflow(long long x) {
    return x > numeric_limits<int>::max() || x < numeric_limits<int>::min();
}

bool checkFloatOverflow(double x) {
    return x > numeric_limits<float>::max() || x < -numeric_limits<float>::max();
}

int main() {
    double a, b;
    char op;
    cout << "Enter operand1: ";
    if(!(cin >> a)) return 0;
    cout << "Enter operator (+ - * / %): ";
    if(!(cin >> op)) return 0;
    cout << "Enter operand2: ";
    if(!(cin >> b)) return 0;

    if (op == '%') {
        int x = static_cast<int>(a);
        int y = static_cast<int>(b);
        if (y == 0) {
            cout << "Error: Modulo by zero\n";
            return 0;
        }
        long long r = static_cast<long long>(x) % static_cast<long long>(y);
        if (checkIntOverflow(r)) {
            cout << "Warning: Overflow for int\n";
        }
        cout << "Result = " << r << endl;
        return 0;
    }

    double result = 0;

    if (op == '+') result = a + b;
    else if (op == '-') result = a - b;
    else if (op == '*') result = a * b;
    else if (op == '/') {
        if (b == 0) {
            cout << "Error: Division by zero\n";
            return 0;
        }
        result = a / b;
    } else {
        cout << "Invalid operator\n";
        return 0;
    }

    if (checkFloatOverflow(result) || !isfinite(result)) {
        cout << "Warning: Overflow/Underflow for float\n";
    }

    cout << "Result = " << result << endl;

    return 0;
}
