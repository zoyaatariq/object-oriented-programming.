/* 5. Caesar Cipher and XOR encryption */
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; getline(cin,s);
    int key; cin>>key;
    string caesar=s, xorv=s;

    for(int i=0;i<s.size();i++) caesar[i]=char(s[i]+key);
    for(int i=0;i<s.size();i++) xorv[i]=char(s[i]^key);

    cout<<caesar<<endl<<xorv;
}
