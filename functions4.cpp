#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    double expr1 = (a * b) / c;
    double expr2 = (a / c) * b;

    cout << "Result of (a*b)/c = " << expr1 << endl;
    cout << "Result of (a/c)*b = " << expr2 << endl;

    double diff = fabs(expr1 - expr2);
    cout << "Difference = " << diff << endl;

    double eps = 1.0;
    while ((1.0 + eps) != 1.0) eps /= 2.0;
    eps *= 2.0;

    cout << "Smallest detectable difference (epsilon) = " << eps << endl;

    return 0;
}
