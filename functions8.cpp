#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    double sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    double mean = sum / n;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[i]) swap(a[i], a[j]);

    double median;
    if (n % 2 == 0) median = (a[n/2] + a[n/2 - 1]) / 2;
    else median = a[n/2];

    double mode = a[0], maxCount = 1;
    for (int i = 0; i < n; i++) {
        int c = 1;
        for (int j = i+1; j < n; j++)
            if (a[j] == a[i]) c++;
        if (c > maxCount) {
            maxCount = c;
            mode = a[i];
        }
    }

    double var = 0;
    for (int i = 0; i < n; i++)
        var += (a[i] - mean)*(a[i] - mean);
    var /= n;

    double sd = sqrt(var);

    cout << mean << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << sd << endl;
    cout << var << endl;

    return 0;
}
