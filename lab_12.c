// Сумма цифр числа

#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    if (n < 0) n = -n;

    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    
    printf("%d\n", sum);
    return 0;
}
