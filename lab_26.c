// В налоговой инспекции составлен реестр налогоплательщиков, в котором для каждого из них указаны фамилия и сумма уплаченного налога. Упорядочить налогоплательщиков по убыванию налоговой суммы.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

typedef struct {
    char surname[MAX_NAME];
    double tax;
} Taxpayer;

int compare(const void *a, const void *b) {
    double taxA = ((Taxpayer *)a)->tax;
    double taxB = ((Taxpayer *)b)->tax;

    if (taxA < taxB) return 1;
    if (taxA > taxB) return -1;
    return 0;
}

int main() {
    int n;
    
    printf("Количество налогоплательщиков: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Ошибка\n");
        return 1;
    }

    Taxpayer *list = malloc(n * sizeof(Taxpayer));
    if (!list) {
        printf("Ошибка\n");
        return 1;
    }

    printf("ФИО и сумма налога:\n");
    for (int i = 0; i < n; i++) {
        printf("Запись: %d: ", i + 1);
        scanf("%s %lf", list[i].surname, &list[i].tax);
    }

 
    qsort(list, n, sizeof(Taxpayer), compare);

    printf("\nРезультат:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", list[i].surname, list[i].tax);
    }

    free(list);
    return 0;
}