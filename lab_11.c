// Алгоритм поиска Чисел Фибоначчи

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Количество чисел

    int a = 0, b = 1, c;

    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");
    return 0;
}
