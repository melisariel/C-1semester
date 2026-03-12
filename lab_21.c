// Заменить каждый отрицательный элемент массива его абсолютной величиной; все элементы с четными номерами увеличить в 5 раз; элементы, кратные 7, уменьшить в 7 раз

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) arr[i] = -arr[i];
        if ((i + 1) % 2 == 0) arr[i] *= 5; // Индексация с 0!!
        if (arr[i] % 7 == 0) arr[i] /= 7;
    }

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
