#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float num, sum = 0, sum_squares = 0, smallest, largest, average, range, std_dev;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    scanf("%f", &num);

    smallest = largest = num;
    sum = num;
    sum_squares = num * num;

    for (i = 1; i < n; i++) {
        scanf("%f", &num);
        sum += num;
        sum_squares += num * num;
        if (num < smallest)
            smallest = num;
        if (num > largest)
            largest = num;
    }

    average = sum / n;
    range = largest - smallest;
    std_dev = sqrt((sum_squares / n) - (average * average));

    printf("Smallest = %.2f\nLargest = %.2f\nAverage = %.2f\n", smallest, largest, average);
    printf("Range = %.2f\nStandard Deviation = %.2f\n", range, std_dev);

    return 0;
}
