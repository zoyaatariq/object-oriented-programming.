/* str_ops.c */
#include <stdio.h>

/* my_strlen */
int my_strlen(const char *s){
    int i=0; while(s[i]) ++i; return i;
}

/* reverse in-place */
void my_reverse(char *s){
    int n = my_strlen(s), i;
    for(i=0;i<n/2;i++){
        char tmp = s[i]; s[i]=s[n-1-i]; s[n-1-i]=tmp;
    }
}

/* substring: copy s[start..start+len-1] into dest (ensure dest large enough) */
void my_substring(const char *s, int start, int len, char *dest){
    int n = my_strlen(s);
    int i;
    if (start<0) start=0;
    if (start>n) { dest[0]=0; return; }
    for(i=0;i<len && (start+i)<n; ++i) dest[i]=s[start+i];
    dest[i]=0;
}

/* concat: dest must be large enough */
void my_concat(char *dest, const char *a){
    int i = my_strlen(dest), j=0;
    while(a[j]) { dest[i++]=a[j++]; }
    dest[i]=0;
}

/* frequency */
int freq_char(const char *s, char c){
    int i=0, cnt=0;
    while(s[i]) { if (s[i]==c) ++cnt; ++i; }
    return cnt;
}

int main(){
    char s1[200] = "Programming";
    printf("String: %s\n", s1);
    printf("Length: %d\n", my_strlen(s1));
    char copy[200]; int i;
    /* reverse */
    for(i=0;s1[i];++i) copy[i]=s1[i]; copy[i]=0;
    my_reverse(copy);
    printf("Reversed: %s\n", copy);
    /* substring */
    char sub[50];
    my_substring(s1, 3, 4, sub);
    printf("Substring(3,4): %s\n", sub);
    /* concat */
    char cat[400] = "Hello ";
    my_concat(cat, s1);
    printf("Concatenation: %s\n", cat);
    /* freq */
    printf("Frequency of 'g' = %d\n", freq_char(s1,'g'));
    return 0;
}
