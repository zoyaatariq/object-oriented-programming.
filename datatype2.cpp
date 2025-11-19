/* 2. Implement string operations without built-in functions */
#include <iostream>
using namespace std;

int length(char s[]){ int i=0; while(s[i]) i++; return i; }
void reverseStr(char s[]){ int i=0,j=length(s)-1; while(i<j){ char t=s[i]; s[i]=s[j]; s[j]=t; i++; j--; } }
void concat(char a[], char b[]){ int i=length(a), j=0; while(b[j]) a[i++]=b[j++]; a[i]=0; }
int freq(char s[], char c){ int f=0; for(int i=0;s[i];i++) if(s[i]==c) f++; return f; }

int main(){
    char s[200], t[200];
    cin.getline(s,200);
    cout << length(s) << endl;
    reverseStr(s);
    cout << s << endl;
    cin.getline(t,200);
    concat(s,t);
    cout << s << endl;
    char c; cin >> c;
    cout << freq(s,c);
}
