#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, discriminant, root1, root2;

    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    // Check for valid 'a' using conditional operator
    (a == 0) ? printf("Invalid! 'a' cannot be zero for a quadratic equation.\n") :
    (
        discriminant = b * b - 4 * a * c,
        (discriminant > 0) ? (
            root1 = (-b + sqrt(discriminant)) / (2 * a),
            root2 = (-b - sqrt(discriminant)) / (2 * a),
            printf("Real and Distinct Roots: %.2f and %.2f\n", root1, root2)
        ) :
        (discriminant == 0) ? (
            root1 = root2 = -b / (2 * a),
            printf("Real and Equal Roots: %.2f and %.2f\n", root1, root2)
        ) :
        printf("Imaginary Roots.\n")
    );

    return 0;
}
