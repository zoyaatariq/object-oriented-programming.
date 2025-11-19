/* 3. Boolean expression evaluator and truth table generator */
#include <iostream>
using namespace std;

int AND(int a,int b){ return a&&b; }
int OR(int a,int b){ return a||b; }
int NOT(int a){ return !a; }
int XOR(int a,int b){ return a!=b; }

int main(){
    int a,b,c;
    for(a=0;a<2;a++)
        for(b=0;b<2;b++)
            for(c=0;c<2;c++)
                cout<<a<<" "<<b<<" "<<c<<" "<<XOR(AND(a,b),NOT(c))<<endl;
}
