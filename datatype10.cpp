/* 9. Count uppercase, lowercase, digits, whitespace, special chars */
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; getline(cin,s);
    int u=0,l=0,d=0,w=0,sp=0;

    for(char c:s){
        if(c>='A'&&c<='Z') u++;
        else if(c>='a'&&c<='z') l++;
        else if(c>='0'&&c<='9') d++;
        else if(c==' ') w++;
        else sp++;
    }
    cout<<u<<" "<<l<<" "<<d<<" "<<w<<" "<<sp;
}
