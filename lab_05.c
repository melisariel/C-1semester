// Тип студента по оценкам

#include <stdio.h>

int main() {
    int a, b, c;
    double avg;

    scanf("%d %d %d", &a, &b, &c);

    avg = (a + b + c) / 3.0;

    if (avg >= 4.5) {
        printf("avg score = %.2lf\n", avg);
    } else if (avg >= 3.5) {
        printf("avg score = %.2lf\n", avg);
    } else if (avg >= 2.5) {
        printf("avg score = %.2lf\n", avg);
    } else {
        printf("avg score = %.2lf\n", avg);
    }

    return 0;
}
