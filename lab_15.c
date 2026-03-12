#include <stdio.h>

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y); // Координаты точки

    // Первая область: I четверть и выше y = -x + 1
    // Вторая область: II четверть и ниже y = -x - 1
    // Третья область: IV четверть и ниже y = -x - 1

    if (x > 0 && y > 0 && y > -x + 1 || x < 0 && y > 0 && y < -x - 1 || x > 0 && y < 0 && y < -x - 1) {
        printf("Prinadlezhit\n");
    } else {
        printf("Ne prinadlezhit\n");
        }
    return 0;

}