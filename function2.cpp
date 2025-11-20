// Question 2: Implement string ops (length, reverse, substring, concat, freq) without built-in functions
#include <bits/stdc++.h>
using namespace std;
int mylen(const char *s){ int i=0; while(s[i]) ++i; return i; }
void myreverse(char *s){
    int n = mylen(s);
    for(int i=0;i<n/2;i++) swap(s[i], s[n-1-i]);
}
char* mysubstr(const char *s, int start, int len){
    int n = mylen(s);
    if(start<0) start = 0;
    if(start>n) start = n;
    if(len<0) len = 0;
    int m = min(len, n-start);
    char *res = (char*)malloc(m+1);
    for(int i=0;i<m;i++) res[i]=s[start+i];
    res[m]=0;
    return res;
}
char* myconcat(const char *a, const char *b){
    int na=mylen(a), nb=mylen(b);
    char *r = (char*)malloc(na+nb+1);
    for(int i=0;i<na;i++) r[i]=a[i];
    for(int j=0;j<nb;j++) r[na+j]=b[j];
    r[na+nb]=0; return r;
}
int freqchar(const char *s, char c){
    int cnt=0;
    for(int i=0;s[i];i++) if(s[i]==c) ++cnt;
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in;
    getline(cin, in);
    // demonstrate operations
    vector<string> parts;
    // Input format examples:
    // To get specific op, we will prompt (but as single-run):
    // For automated use, we'll just perform all ops on input line
    cout << "Length: " << mylen(in.c_str()) << "\n";
    char *cpy = strdup(in.c_str());
    myreverse(cpy);
    cout << "Reversed: " << cpy << "\n";
    free(cpy);
    char *sub = mysubstr(in.c_str(), 0, min(5, (int)in.size()));
    cout << "Substring(0,5): " << sub << "\n";
    free(sub);
    char *cat = myconcat(in.c_str(), "++APPEND");
    cout << "Concat with \"++APPEND\": " << cat << "\n";
    free(cat);
    if(in.size()>0){
        char ch = in[0];
        cout << "Freq of '" << ch << "': " << freqchar(in.c_str(), ch) << "\n";
    }
    return 0;
}
