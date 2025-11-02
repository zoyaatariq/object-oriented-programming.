#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);

    // Using conditional operator (?:)
    (op == '+') ? printf("Result = %.2f", a + b) :
    (op == '-') ? printf("Result = %.2f", a - b) :
    (op == '*') ? printf("Result = %.2f", a * b) :
    (op == '/' && b != 0) ? printf("Result = %.2f", a / b) :
    (op == '%' && (int)b != 0) ? printf("Result = %d", (int)a % (int)b) :
    (op == '/' && b == 0) ? printf("Error: Division by zero!") :
    printf("Invalid operator!");

    return 0;
}
