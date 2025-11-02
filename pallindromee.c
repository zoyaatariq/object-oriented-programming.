#include <stdio.h>

int main() {
    int num, temp, rev = 0, rem;
    int start, end;

    // Single number check
    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    if (rev == num)
        printf("%d is a Palindrome.\n", num);
    else
        printf("%d is not a Palindrome.\n", num);

    // Range-based palindrome printing
    printf("\nEnter range (start end): ");
    scanf("%d %d", &start, &end);

    printf("Palindrome numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        int n = i, reversed = 0, digit;
        while (n != 0) {
            digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }
        if (i == reversed)
            printf("%d ", i);
    }

    return 0;
}
