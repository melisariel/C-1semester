// Положение квадрата и окружности

#include <stdio.h>

int main() {
    long long x, y; // координаты центра
    long long r; // радиус
    long long a; // сторона квадрата

    scanf("%lld %lld", &x, &y);
    scanf("%lld", &r);
    scanf("%lld", &a);

    long long r2 = r * r;
    long long a2 = a * a;

    if (4 * r2 < a2)
        printf("Окружность внутри квадрата\n");
    else if (4 * r2 == a2)
        printf("Окружность касается сторон квадрата\n");
    else if (2 * r2 < a2)
        printf("Окружность и квадрат пересекаются\n");
    else if (2 * r2 == a2)
        printf("Квадрат вписан в окружность\n");
    else
        printf("Квадрат полностью внутри окружности\n");

    return 0;
}
