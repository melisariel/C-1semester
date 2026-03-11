// Пройденный путь с разными скоростями

#include <stdio.h>

int main() {
    double V, U, t1, t2, s;

    scanf("%lf %lf", &V, &U);

    if (U >= V) {
        printf("Error\n");
        return 1;
    }

    scanf("%lf %lf", &t1, &t2);

    s = V * t1 + (V - U) * t2;

    printf("%lf\n", s);

    return 0;
}
