#include <stdio.h>

int main() {
    int i, temp;
    int hot = 0, pleasant = 0, cold = 0;
    int temps[] = {55,62,68,74,59,45,41,58,60,67,65,78,82,88,91,92,90,93,87,80,78,79,72,68,61,59};
    int n = sizeof(temps)/sizeof(temps[0]);

    for (i = 0; i < n; i++) {
        temp = temps[i];
        printf("Temperature %d°F: ", temp);

        if (temp >= 85) {
            printf("Hot Day\n");
            hot++;
        } else if (temp >= 60 && temp <= 84) {
            printf("Pleasant Day\n");
            pleasant++;
        } else {
            printf("Cold Day\n");
            cold++;
        }
    }

    printf("\nHot Days: %d\nPleasant Days: %d\nCold Days: %d\n", hot, pleasant, cold);
    return 0;
}
