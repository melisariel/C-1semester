// Простейший калькулятор

#include <stdio.h>

int main() {
    double a, b, res;
    char op;

    scanf("%lf %lf", &a, &b);
    scanf(" %c", &op);

    switch (op) {
        case '+':
        res = a + b;
        printf("%lf\n", res);
        break;

        case '-':
        res = a - b;
        printf("%lf\n", res);
        break;

        case '*':
        res = a * b;
        printf("%lf\n", res);
        break;

        case '/':
        if (b == 0) {
            printf("Error\n");
        } else {
            res = a / b;
            printf("%lf\n", res);
        }
        break;

    default:
        printf("Error\n");
    }

    return 0;
}
