#include <stdio.h>

int main() {
    int year, count = 0, next;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
        printf("%d is a Leap Year.\n", year);
    else {
        printf("%d is NOT a Leap Year.\n", year);
        printf("Next 5 leap years are: ");
        next = year + 1;
        while (count < 5) {
            if ( (next % 4 == 0 && next % 100 != 0) || (next % 400 == 0) ) {
                printf("%d ", next);
                count++;
            }
            next++;
        }
    }

    return 0;
}
