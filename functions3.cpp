// Question 3: Boolean expression evaluator (AND, OR, NOT, XOR). Extend to truth table for 3 vars.
#include <bits/stdc++.h>
using namespace std;
int evalToken(const string &tok, const vector<int>&vars){
    if(tok=="AND"||tok=="and"||tok=="&") return 2;
    if(tok=="OR"||tok=="or"||tok=="|") return 1;
    if(tok=="XOR"||tok=="xor"||tok=="^") return 3;
    if(tok=="NOT"||tok=="not"||tok=="!") return 4;
    // variable like A,B,C or 0/1
    if(tok=="0") return 0;
    if(tok=="1") return 1;
    if(tok.size()==1 && isalpha((unsigned char)tok[0])){
        char c = toupper(tok[0]);
        if(c=='A') return vars[0];
        if(c=='B') return vars[1];
        if(c=='C') return vars[2];
    }
    return 0;
}
int applyOpStr(const string &op, int a, int b=0){
    string o=op;
    for(auto &ch:o) ch=toupper(ch);
    if(o=="AND"||o=="&") return a & b;
    if(o=="OR"||o=="|") return a | b;
    if(o=="XOR"||o=="^") return a ^ b;
    if(o=="NOT"||o=="!") return !a;
    return 0;
}
// very simple evaluator supporting parentheses, NOT unary, and binary ops AND/OR/XOR
int precedence(const string &op){
    string o=op; for(auto &ch:o) ch=toupper(ch);
    if(o=="NOT") return 3;
    if(o=="AND") return 2;
    if(o=="XOR") return 1;
    if(o=="OR") return 0;
    return -1;
}
vector<string> tokenize(string s){
    vector<string> t;
    for(size_t i=0;i<s.size();){
        if(isspace((unsigned char)s[i])) { ++i; continue; }
        if(s[i]=='('||s[i]==')'){ t.push_back(string(1,s[i])); ++i; continue; }
        if(isalpha((unsigned char)s[i])){
            string w;
            while(i<s.size() && isalpha((unsigned char)s[i])) { w.push_back(s[i]); ++i; }
            t.push_back(w);
            continue;
        }
        if(isdigit((unsigned char)s[i])){
            string w;
            while(i<s.size() && isdigit((unsigned char)s[i])) { w.push_back(s[i]); ++i; }
            t.push_back(w); continue;
        }
        // operators like &,|,^,!, but treat words first
        string w(1,s[i]); t.push_back(w); ++i;
    }
    return t;
}
int evalExpr(string expr, const vector<int>&vars){
    auto toks = tokenize(expr);
    // convert symbol ops to words
    for(auto &tk: toks){
        if(tk=="&") tk="AND";
        if(tk=="|") tk="OR";
        if(tk=="^") tk="XOR";
        if(tk=="!") tk="NOT";
    }
    // Shunting-yard to RPN
    vector<string> out; vector<string> ops;
    for(size_t i=0;i<toks.size();i++){
        string tk=toks[i];
        if(tk=="0"||tk=="1"|| (tk.size()==1 && isalpha((unsigned char)tk[0])) ) out.push_back(tk);
        else if(tk=="AND"||tk=="OR"||tk=="XOR"||tk=="NOT"){
            while(!ops.empty() && ops.back()!="(" &&
                  ((precedence(ops.back())>precedence(tk)) || (precedence(ops.back())==precedence(tk) && tk!="NOT"))){
                out.push_back(ops.back()); ops.pop_back();
            }
            ops.push_back(tk);
        } else if(tk=="(") ops.push_back(tk);
        else if(tk==")"){
            while(!ops.empty() && ops.back()!="("){ out.push_back(ops.back()); ops.pop_back(); }
            if(!ops.empty() && ops.back()=="(") ops.pop_back();
        }
    }
    while(!ops.empty()){ out.push_back(ops.back()); ops.pop_back(); }
    // eval RPN
    vector<int> st;
    for(auto &tok: out){
        if(tok=="0"||tok=="1"|| (tok.size()==1 && isalpha((unsigned char)tok[0])) ){
            if(tok=="0") st.push_back(0);
            else if(tok=="1") st.push_back(1);
            else {
                char c=toupper(tok[0]);
                if(c=='A') st.push_back(vars[0]);
                else if(c=='B') st.push_back(vars[1]);
                else if(c=='C') st.push_back(vars[2]);
                else st.push_back(0);
            }
        } else if(tok=="NOT"){
            int a=st.back(); st.pop_back();
            st.push_back(!a);
        } else {
            int b=st.back(); st.pop_back();
            int a=st.back(); st.pop_back();
            if(tok=="AND") st.push_back(a & b);
            else if(tok=="OR") st.push_back(a | b);
            else if(tok=="XOR") st.push_back(a ^ b);
        }
    }
    return st.empty()?0:st.back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    // if input is "TRUTH" produce truth table for 3 vars
    if(line=="TRUTH"){
        cout << "A B C | F\n";
        for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int c=0;c<2;c++){
            vector<int> v={a,b,c};
            // example expression: (A AND B) OR (NOT C)
            int f = evalExpr("A AND B OR NOT C", v);
            cout << a << ' ' << b << ' ' << c << " | " << f << "\n";
        }
        return 0;
    }
    // otherwise evaluate given expression with variables A/B/C allowed (use 0/1)
    vector<int> vars = {0,0,0};
    cout << evalExpr(line, vars) << "\n";
    return 0;
}
