#include <stdio.h>

int main() {
    int guests, chairs, i;
    long arrangements = 1;

    printf("Enter number of guests: ");
    scanf("%d", &guests);
    printf("Enter number of chairs: ");
    scanf("%d", &chairs);

    if (chairs > guests) {
        printf("Chairs cannot be more than guests!\n");
        return 0;
    }

    for (i = 0; i < chairs; i++)
        arrangements *= (guests - i);

    printf("Number of possible arrangements = %ld\n", arrangements);
    return 0;
}
