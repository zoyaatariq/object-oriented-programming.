#include <stdio.h>

int main() {
    float marks[5], total = 0, percentage;
    int i, failCount = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);

        if (marks[i] < 40)  // assuming 40 is pass mark
            failCount++;

        total += marks[i];
    }

    percentage = total / 5;

    if (failCount > 1) {
        printf("Repeat Year\n");
    } else {
        if (percentage >= 90)
            printf("Grade: A\n");
        else if (percentage >= 80)
            printf("Grade: B\n");
        else if (percentage >= 70)
            printf("Grade: C\n");
        else if (percentage >= 50)
            printf("Grade: D\n");
        else
            printf("Grade: F\n");
    }

    printf("Percentage: %.2f%%\n", percentage);
    return 0;
}
