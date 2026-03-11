// Тип треугольника по сторонам

#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Треугольник не существует\n");
        return 0;
    }

    if (a == b && b == c) {
        printf("Равнобедренный\n");
    } else if (a == b || b == c || a == c) {
        printf("Равносторонний\n");
    } else {
        printf("Неправильный\n");
    }

    if (a*a + b*b == c*c ||
        a*a + c*c == b*b ||
        b*b + c*c == a*a) {
        printf("Правильный\n");
    }

    return 0;
}