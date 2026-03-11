// Пройдет ли контейнер в дверь?

#include <stdio.h>

int main() {
    long long a, b, c; // контейнер
    long long m, n;    // двери

    scanf("%lld %lld %lld", &a, &b, &c);
    scanf("%lld %lld", &m, &n);

    if (
        ( (a <= m && b <= n) || (a <= n && b <= m) ) ||
        ( (a <= m && c <= n) || (a <= n && c <= m) ) ||
        ( (b <= m && c <= n) || (b <= n && c <= m) )
       )
        printf("Контейнер пройдет\n");
    else
        printf("Контейнер не пройдет\n");

    return 0;
}
