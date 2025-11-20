#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    int a[r][c], b[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> b[i][j];

    float f[r][c];
    double d[r][c];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            f[i][j] = float(a[i][j] * b[i][j]);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            d[i][j] = double(a[i][j] * b[i][j]);

    cout << "Float Result:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << f[i][j] << " ";
        cout << endl;
    }

    cout << "Double Result:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << d[i][j] << " ";
        cout << endl;
    }

    return 0;
}
