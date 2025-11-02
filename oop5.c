#include <stdio.h>

int main() {
    int n, i, id;
    float wage, hours, gross, net, total_payroll = 0, total_employees = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Employee ID: ");
        scanf("%d", &id);
        printf("Enter Hourly Wage: ");
        scanf("%f", &wage);
        printf("Enter Hours Worked: ");
        scanf("%f", &hours);

        // Calculate gross with overtime
        if (hours > 40)
            gross = (40 * wage) + ((hours - 40) * 1.5 * wage);
        else
            gross = hours * wage;

        // Tax deduction
        net = gross - (0.03625 * gross);

        printf("Employee %d Net Pay = Rs %.2f\n", id, net);

        total_payroll += net;
        total_employees++;
    }

    printf("\nTotal Payroll = Rs %.2f\n", total_payroll);
    printf("Average Pay = Rs %.2f\n", total_payroll / total_employees);

    return 0;
}
