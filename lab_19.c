// В массиве каждый третий элемент заменяет полусуммой двух предыдущех, а стоящий перед ним - полусуммой соседних с ним эелементов

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 2; i < n; i += 3) {
        int prev2 = arr[i-2];
        int prev1 = arr[i-1];

        arr[i] = (prev2 + prev1)/2;
        arr[i-1] = (prev2 + arr[i])/2;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
