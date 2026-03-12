// По заданным дввум массивам целых чисел сформировать массив-обьединение (без повторений) и массив-пересечение

#include <stdio.h>

int main() {
    int n1, n2;

    if (scanf("%d", &n1) != 1 || n1 < 0) return 1;

    int arr1[n1];

    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    if (scanf("%d", &n2) != 1 || n2 < 0) return 1;

    int arr2[n2];

    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int unArr[n1 + n2];
    int unSize = 0;

}
