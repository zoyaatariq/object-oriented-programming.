#include <stdio.h>

int main() {
    int i, j, space, lines = 20;

    for (i = 1; i <= lines; i++) {
        // print spaces
        for (space = i; space < lines; space++)
            printf(" ");
        // print Xs
        for (j = 1; j <= (2 * i - 1); j++)
            printf("X");
        printf("\n");
    }

    return 0;
}
