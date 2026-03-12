// Решение квадратного уравнения

#include <stdio.h>
#include <math.h>

int main() {
    
    double a, b, c;
    double D, x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Ошибка\n");
            } else {
                printf("Ошибка\n");
            } 
        } else {
            x1 = -c / b;
            printf("%lf\n", x1);
        }
        return 0;
    }

    D = b * b - 4 * a * c;

    if (D < 0) {
        printf("Ошибка\n");
    } else if (D == 0) {
        x1 = -b / (2 * a);
        printf("%lf\n", x1);
    } else {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("%lf %lf\n", x1, x2);
    }

    return 0;
}

