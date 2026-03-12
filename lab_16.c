// Алгоритм поиска min и max элементов в массиве и их позицию

#include <stdio.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0){
        return 1;
    }

    int arr[n];
    
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }

    int max = arr[0], min = arr[0];
    int maxIndex = 0, minIndex = 0;

    for(int i = 1; i < n; i++) {

        if(arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }

        if(arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }

    }

    printf("min: %d, позиция: %d\n", min, minIndex);
    printf("max: %d, позиция: %d\n", max, maxIndex);

    return 0;

}
