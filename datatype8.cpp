/* 7. Temperature conversion using float vs double */
#include <iostream>
using namespace std;

int main(){
    float c1; double c2;
    cin>>c1>>c2;
    float f1 = (c1*9/5)+32, k1 = c1+273.15f;
    double f2=(c2*9/5)+32, k2=c2+273.15;

    cout<<f1<<" "<<k1<<endl<<f2<<" "<<k2;
}
