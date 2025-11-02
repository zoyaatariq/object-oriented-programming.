#include <stdio.h>

int main() {
    float marks[5], total = 0, average, percentage;
    int i;

    for(i = 0; i < 5; i++) {
        printf("Enter marks of subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    average = total / 5;
    percentage = (total / 500) * 100;

    printf("Total = %.2f\nAverage = %.2f\nPercentage = %.2f%%\n", total, average, percentage);

    if(percentage >= 90)
        printf("Grade: A+");
    else if(percentage >= 80)
        printf("Grade: A");
    else if(percentage >= 70)
        printf("Grade: B");
    else if(percentage >= 60)
        printf("Grade: C");
    else if(percentage >= 50)
        printf("Grade: D");
    else
        printf("Grade: F (Fail)");

    return 0;
}
