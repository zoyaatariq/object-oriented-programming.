#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int main() {
    int day, month, year, valid = 1;
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &day, &month, &year);

    // Adjust February for leap year
    if (isLeapYear(year))
        daysInMonth[2] = 29;

    // Validation checks
    if (year < 1)
        valid = 0;
    else if (month < 1 || month > 12)
        valid = 0;
    else if (day < 1 || day > daysInMonth[month])
        valid = 0;

    if (!valid) {
        printf("Invalid date!\n");
        return 0;
    }

    printf("Valid date!\n");

    // Zeller’s Congruence (formula to find day of week)
    int d = day;
    int m = month;
    int y = year;

    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;
    int h = (d + 13*(m + 1)/5 + k + k/4 + j/4 + 5*j) % 7;

    // Convert result to day name (0 = Saturday)
    switch(h) {
        case 0: printf("Day of the week: Saturday\n"); break;
        case 1: printf("Day of the week: Sunday\n"); break;
        case 2: printf("Day of the week: Monday\n"); break;
        case 3: printf("Day of the week: Tuesday\n"); break;
        case 4: printf("Day of the week: Wednesday\n"); break;
        case 5: printf("Day of the week: Thursday\n"); break;
        case 6: printf("Day of the week: Friday\n"); break;
    }

    return 0;
}
