/* expr_eval.c
   Simple tokenizer + evaluator which recognizes ints, floats (suffix f) and doubles (decimal).
   It supports expressions of the form:
     number op number
     number op number op number
   with operator precedence for * and / over + and -.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { T_INT, T_FLOAT, T_DOUBLE } Type;

typedef struct {
    double value;   /* numeric value (we store in double for evaluation) */
    Type type;
} Num;

Type detect_type(const char *s) {
    int i, dot = 0;
    int len = strlen(s);
    if (len > 0 && (s[len-1] == 'f' || s[len-1] == 'F')) return T_FLOAT;
    for (i=0; s[i]; ++i) if (s[i]=='.' || tolower(s[i])=='e') dot = 1;
    return dot ? T_DOUBLE : T_INT;
}

Num parse_num(const char *s) {
    Num n; n.type = detect_type(s);
    /* remove trailing f/F if present */
    char buf[64]; strncpy(buf, s, 63); buf[63]=0;
    int L = strlen(buf);
    if (L>0 && (buf[L-1]=='f' || buf[L-1]=='F')) buf[L-1]=0;
    n.value = atof(buf);
    return n;
}

int is_op(char c){ return c=='+'||c=='-'||c=='*'||c=='/'; }

double apply(double a, double b, char op) {
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return b!=0 ? a/b : (a>=0?1e308:-1e308);
    }
    return 0;
}

/* manual promotion: result type is max rank among operands (int<float<double) */
Type promoted(Type a, Type b){
    if (a==T_DOUBLE||b==T_DOUBLE) return T_DOUBLE;
    if (a==T_FLOAT||b==T_FLOAT) return T_FLOAT;
    return T_INT;
}

int main(){
    char expr[200];
    printf("Enter expression (e.g. 5 + 3.2 * 2.0):\n> ");
    fgets(expr, sizeof(expr), stdin);
    /* tokenize by spaces */
    char *token[10]; int tcount=0;
    char *p = strtok(expr, " \t\n");
    while(p && tcount<10){ token[tcount++]=p; p=strtok(NULL," \t\n"); }

    if (tcount==0){ printf("Empty.\n"); return 0; }

    /* parse forms: num op num [op num] */
    if (tcount!=3 && tcount!=5){ printf("Unsupported format. Use 'a op b' or 'a op b op c'.\n"); return 0; }

    Num n1 = parse_num(token[0]);
    char op1 = token[1][0];
    Num n2 = parse_num(token[2]);

    if (tcount==3){
        Type resType = promoted(n1.type, n2.type);
        double raw = apply(n1.value, n2.value, op1);
        printf("Promoted type: %s\n", resType==T_DOUBLE?"double":resType==T_FLOAT?"float":"int");
        if (resType==T_INT) printf("Result (int) = %d\n",(int)raw);
        else if (resType==T_FLOAT) printf("Result (float) = %.7g\n",(float)raw);
        else printf("Result (double) = %.15g\n", raw);
        return 0;
    }

    /* tcount == 5 */
    char op2 = token[3][0];
    Num n3 = parse_num(token[4]);

    /* operator precedence: do * or / first */
    double val1, val2, final;
    Type tA=n1.type, tB=n2.type, tC=n3.type;
    Type resType;
    if ((op1=='*' || op1=='/') || !(op2=='*' || op2=='/')) {
        /* evaluate left first if op1 has precedence or no precedence on op2 */
        val1 = apply(n1.value, n2.value, op1);
        val2 = apply(val1, n3.value, op2);
    } else {
        /* op2 has precedence */
        val1 = apply(n2.value, n3.value, op2);
        val2 = apply(n1.value, val1, op1);
    }
    resType = promoted(promoted(tA,tB), tC);
    if (resType==T_INT) printf("Promoted type: int\nResult (int) = %d\n", (int)val2);
    else if (resType==T_FLOAT) printf("Promoted type: float\nResult (float) = %.7g\n", (float)val2);
    else printf("Promoted type: double\nResult (double) = %.15g\n", val2);
    return 0;
}
