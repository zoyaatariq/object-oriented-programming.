#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int up=0, low=0, dig=0, ws=0, sp=0;

    for(char c : s) {
        if (c >= 'A' && c <= 'Z') up++;
        else if (c >= 'a' && c <= 'z') low++;
        else if (c >= '0' && c <= '9') dig++;
        else if (c == ' ') ws++;
        else sp++;
    }

    cout << up << endl;
    cout << low << endl;
    cout << dig << endl;
    cout << ws << endl;
    cout << sp << endl;

    return 0;
}
