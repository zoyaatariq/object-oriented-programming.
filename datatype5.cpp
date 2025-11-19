/* 4. Demonstrate floating-point errors and find epsilon */
#include <iostream>
using namespace std;

int main(){
    float a=10.0f, b=3.0f, c=3.0f;
    cout << (a*b)/c << " " << a*(b/c) << endl;

    double eps=1.0;
    while(1.0 + eps/2 > 1.0) eps/=2;
    cout << eps;
}
