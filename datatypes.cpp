/* 1. Arithmetic expression evaluator with type promotion */
#include <iostream>
#include <string>
using namespace std;

bool isFloat(string s){ return s.find('f') != string::npos || s.find('F') != string::npos; }
bool isDouble(string s){ return s.find('.') != string::npos; }

int main(){
    string a, op1, b, op2, c;
    cin >> a >> op1 >> b >> op2 >> c;

    bool needDouble = isDouble(a) || isDouble(b) || isDouble(c);
    bool needFloat = isFloat(a) || isFloat(b) || isFloat(c);

    if(needDouble){
        double A=stod(a), B=stod(b), C=stod(c), r1, r;
        if(op2=="*"||op2=="/"){
            r1 = (op2=="*")? B*C : B/C;
            r = (op1=="+")? A+r1 : (op1=="-")? A-r1 : (op1=="*")? A*r1 : A/r1;
        } else {
            r1 = (op1=="*")? A*B : (op1=="/")? A/B : (op1=="+")? A+B : A-B;
            r = (op2=="+")? r1+C : (op2=="-")? r1-C : (op2=="*")? r1*C : r1/C;
        }
        cout << r;
    }
    else if(needFloat){
        float A=stof(a), B=stof(b), C=stof(c), r1, r;
        if(op2=="*"||op2=="/"){
            r1 = (op2=="*")? B*C : B/C;
            r = (op1=="+")? A+r1 : (op1=="-")? A-r1 : (op1=="*")? A*r1 : A/r1;
        } else {
            r1 = (op1=="*")? A*B : (op1=="/")? A/B : (op1=="+")? A+B : A-B;
            r = (op2=="+")? r1+C : (op2=="-")? r1-C : (op2=="*")? r1*C : r1/C;
        }
        cout << r;
    }
    else {
        long long A=stoll(a), B=stoll(b), C=stoll(c), r1, r;
        if(op2=="*"||op2=="/"){
            r1 = (op2=="*")? B*C : B/C;
            r = (op1=="+")? A+r1 : (op1=="-")? A-r1 : (op1=="*")? A*r1 : A/r1;
        } else {
            r1 = (op1=="*")? A*B : (op1=="/")? A/B : (op1=="+")? A+B : A-B;
            r = (op2=="+")? r1+C : (op2=="-")? r1-C : (op2=="*")? r1*C : r1/C;
        }
        cout << r;
    }
}
