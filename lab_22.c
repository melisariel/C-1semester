// Дан целочисленный массив размера N. Проверить, не используя сортировку, яввляется ли он перестановкой, то есть содержит все числа от 1 до N

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *a = malloc(n * sizeof(int));
    if (!a) return 0;

    for (int i = 0; i < n; ++i) if (scanf("%d", &a[i]) != 1) { free(a); return 0; }

    for (int i = 0; i < n; ++i) {
        int x = abs(a[i]);
        if (x < 1 || x > n) { printf("Нет\n"); free(a); return 0; }
        if (a[x-1] < 0) { printf("Нет\n"); free(a); return 0; }
        a[x-1] = -abs(a[x-1]);
    }
    printf("Да\n");
    free(a);
    return 0;
}
