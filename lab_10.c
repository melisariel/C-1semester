// Алгоритм Евклида

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    printf("%d\n", a + b);
    return 0;
}
