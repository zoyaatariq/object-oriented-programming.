#include <stdio.h>
#include <math.h>

int main() {
    float r1, i1, r2, i2;
    float mag1, mag2;

    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &r1, &i1);

    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &r2, &i2);

    // Magnitude = √(real² + imaginary²)
    mag1 = sqrt(r1 * r1 + i1 * i1);
    mag2 = sqrt(r2 * r2 + i2 * i2);

    if (mag1 > mag2)
        printf("First complex number has higher magnitude.\n");
    else if (mag2 > mag1)
        printf("Second complex number has higher magnitude.\n");
    else
        printf("Equal magnitudes.\n");

    return 0;
}
