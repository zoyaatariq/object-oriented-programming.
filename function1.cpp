// Question 1: Evaluate arithmetic expressions with type promotion rules (int, float, double)
#include <bits/stdc++.h>
using namespace std;

// token types
enum TokType {OP, NUM};
struct Token{
    TokType t;
    string s;
};
int prec(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}
bool isOp(char c){ return c=='+'||c=='-'||c=='*'||c=='/'; }

// Value with type tag: 0=int,1=float,2=double
struct Val{
    int tag;
    long double v; // hold numeric value in long double
    long double asDouble() const { return v; }
};
Val makeVal(const string &s){
    // detect suffix 'f' or presence of '.' ; treat numbers with 'f' as float, '.' as double
    if(s.back()=='f' || s.back()=='F'){
        string t = s.substr(0,s.size()-1);
        Val r; r.tag=1; r.v = stof(t);
        return r;
    }
    if(s.find('.')!=string::npos){
        Val r; r.tag=2; r.v = stold(s);
        return r;
    }
    Val r; r.tag=0; r.v = stoll(s);
    return r;
}
Val promote(const Val &a, const Val &b){
    Val r;
    r.tag = max(a.tag, b.tag);
    return r;
}
Val applyOp(const Val &A, const Val &B, char op){
    Val R = promote(A,B);
    long double a = A.asDouble(), b = B.asDouble();
    long double res=0;
    if(op=='+') res = a + b;
    if(op=='-') res = a - b;
    if(op=='*') res = a * b;
    if(op=='/') res = a / b;
    R.v = res;
    // if result type is int, truncate
    if(R.tag==0) R.v = (long long)res;
    if(R.tag==1) R.v = (float)res;
    return R;
}

vector<Token> tokenize(const string &in){
    vector<Token> out;
    string s; 
    for(size_t i=0;i<in.size();){
        if(isspace((unsigned char)in[i])) { ++i; continue; }
        if(isOp(in[i])){
            s = string(1,in[i]); out.push_back({OP,s}); ++i; continue;
        }
        // number (may include . and suffix f)
        string num;
        if(in[i]=='+'||in[i]=='-'){ // unary sign allowed only if part of number
            num.push_back(in[i]); ++i;
        }
        bool seenDot=false;
        while(i<in.size() && (isdigit((unsigned char)in[i]) || in[i]=='.' || in[i]=='f' || in[i]=='F')){
            if(in[i]=='.') seenDot=true;
            num.push_back(in[i]); ++i;
        }
        out.push_back({NUM,num});
    }
    return out;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    if(line.size()==0) return 0;
    auto tokens = tokenize(line);
    // shunting yard to RPN
    vector<string> output;
    vector<char> ops;
    for(auto &tk: tokens){
        if(tk.t==NUM) output.push_back(tk.s);
        else {
            char op = tk.s[0];
            while(!ops.empty() && prec(ops.back())>=prec(op)){
                output.push_back(string(1,ops.back())); ops.pop_back();
            }
            ops.push_back(op);
        }
    }
    while(!ops.empty()){ output.push_back(string(1,ops.back())); ops.pop_back(); }
    // evaluate RPN with Val
    vector<Val> st;
    for(auto &t: output){
        if(t.size()==1 && isOp(t[0])){
            Val b = st.back(); st.pop_back();
            Val a = st.back(); st.pop_back();
            st.push_back(applyOp(a,b,t[0]));
        } else {
            st.push_back(makeVal(t));
        }
    }
    Val res = st.back();
    // print with type info and value
    if(res.tag==0) cout << (long long)res.v << "\n";
    else if(res.tag==1) cout << fixed << setprecision(6) << (float)res.v << "\n";
    else cout << fixed << setprecision(10) << (double)res.v << "\n";
    return 0;
}
