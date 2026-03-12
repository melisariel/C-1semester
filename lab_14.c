// Вычислить значение функции y от x. Значение переменной x и параметров a и b вводить с клавиатуры (Параметр a вещественного типа , параметр b целочисленный, справа от функции даны значения для теста программы): x = 2.3 a = 1.2;-1.5 b = 4;5
// y = ((ax)^(b/4) - 3)^3

#include <stdio.h>
#include <math.h>

int main() {
    double x, a, y;
    int b;
    if (scanf("%lf %lf %d", &x, &a, &b) != 3) return 1;

    double d = a * x; // Основание
    double p = (double)b / 4.0;  // Степень

    double t = pow(d, p); // (a*x)^(b/4)
    double u = t - 3.0;

    y = u * u * u; // Куб выражения
    printf("y = %.6f\n", y);
    return 0;
}
