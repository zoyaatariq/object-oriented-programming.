#include <stdio.h>

int main() {
    float amount, discount, finalAmount;

    printf("Enter purchase amount: Rs ");
    scanf("%f", &amount);

    // Nested conditional operator for discount calculation
    discount = (amount < 100) ? 0 :
               (amount <= 500) ? amount * 0.10 :
               (amount <= 1000) ? amount * 0.15 :
               amount * 0.20;

    finalAmount = amount - discount;

    printf("Discount = Rs %.2f\n", discount);
    printf("Final Price = Rs %.2f\n", finalAmount);

    return 0;
}
