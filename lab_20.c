// Реализовать бинарный поиск. Найти элемент в упорядоченном массиве

#include <stdio.h>

int main() {
    int n = 10, x;
    int arr[10] = {1, 2, 3, 6, 7, 11, 13, 15, 17, 19};

    scanf("%d", &x);

    int min = 0, max = n - 1, mid;

    while (min <= max) {
        mid = (min + max) / 2;

        if (arr[mid] == x) {
            printf("%d Найден в %d\n", x, mid);
            return 0;
        }
        else if (arr[mid] < x)
            min = mid + 1;
        else
            max = mid - 1;
    }

    printf("%d Не найден\n", x);
    return 0;
}
