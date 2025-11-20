// 7. Compound Interest Using Constructor with Default Arguments
#include <iostream>
#include <cmath>
using namespace std;

class CompoundInterest {
    float p, r, t;
    int n;
public:
    CompoundInterest(float P, float R, float T, int N = 1) {
        p = P; r = R; t = T; n = N;
    }
    float calc() {
        return p * pow((1 + r/(n*100)), n*t);
    }
    void display() {
        cout << calc();
    }
};

int main() {
    CompoundInterest c(1000, 5, 2);
    c.display();
    return 0;
}
