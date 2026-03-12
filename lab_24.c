// Найти симметричную последовательность подряд расположенных элементов массива максимальной длины
#include <stdio.h>

int palindrome(int arr[], int start, int end) {
    while (start < end) {
        if (arr[start] != arr[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max_len = 0, max_start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            if (len > max_len && palindrome(arr, i, j)) {
                max_len = len;
                max_start = i;
            }
        }
    }

    for (int i = max_start; i < max_start + max_len; i++)
        printf("%d ", arr[i]);
    printf("\n%d\n", max_len);

    return 0;
}
