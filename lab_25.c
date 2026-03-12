// В текстовый файл построчно записаны целочисленные элементы квадратной матрицы размером 4*4. Прочитайте матрицу из файла в двумерный массив, вычеркните заданную строку и столбец полученную матрицу 3*3 запишите в другой файл.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    printf("Размер матрицы: ");
    scanf("%d", &N);

    int **a = malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++) {
        a[i] = malloc(N * sizeof(int));
    }

    FILE *fin = fopen("input.txt", "r");
    if (!fin) return 1;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            fscanf(fin, "%d", &a[i][j]);
    fclose(fin);

    int row, col;
    printf("Какой номер строки и столбца вычеркнуть: ");
    scanf("%d %d", &row, &col);

    FILE *fout = fopen("output.txt", "w");
    if(!fout) return 1;

    for(int i = 0; i < N; i++) {
        if(i == row) continue;
        for(int j = 0; j < N; j++) {
            if(j == col) continue;
            fprintf(fout, "%d ", a[i][j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);

    for(int i = 0; i < N; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
