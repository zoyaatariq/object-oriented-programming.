#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    printf("Enter a string: ");
    scanf("%s", str);

    strcpy(rev, str);
    strrev(rev); // reverses the string

    if(strcmp(str, rev) == 0)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
