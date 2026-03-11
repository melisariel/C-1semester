// Поиск значения функции F

#include <stdio.h>

int main() {
    double x, F;

    scanf("%lf", &x);

    if (x >= 0 && x <= 3) {
        F = x * x - 3 * x + 9;
        printf("F1 = %.2f\n", F);

        F = 1 / (x * x * x + 6);
        printf("F = %.2f\n", F);
    }
    else {
        printf("Ошибка\n");
    }

    return 0;
}