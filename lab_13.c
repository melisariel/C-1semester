// Пользователь вводит число N (0 < N < 27) реализовать программу из диапозона 0-999, сумма цифр которых равна N

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0 || N >= 27) {
        printf("Ошибка\n");
        return 1;
    }

    for (int i = 0; i <= 999; i++) {
        int temp = i;
        int sum = 0;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
