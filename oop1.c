
#include <stdio.h>

int main() {
    int n, i;
    float num, sum = 0, smallest, largest, average;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    scanf("%f", &num);

    smallest = largest = num;
    sum += num;

    for (i = 1; i < n; i++) {
        scanf("%f", &num);
        sum += num;
        if (num < smallest)
            smallest = num;
        if (num > largest)
            largest = num;
    }

    average = sum / n;

    printf("Smallest = %.2f\n", smallest);
    printf("Largest = %.2f\n", largest);
    printf("Average = %.2f\n", average);

    return 0;
}
