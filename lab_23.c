// Написать программу, которая вводит массив, и вызывает по выбору функцию подсчета суммы нечетных элементов массива или поиска максимума и выводит результат

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] % 2 != 0) sum += arr[i];
        printf("%d\n", sum);

    } else if (choice == 2) {
        int max = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > max) max = arr[i];
        printf("%d\n", max);
    }

    return 0;
}
