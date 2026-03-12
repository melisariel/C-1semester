/* Дана шахматная доска. Для двух различных клеток К1, К2 доски и выбранной пользователем фигуры (король, ферзь, ладья, слон, конь) определить:
Может ли фигура за один ход перейти из К1 в К2?
Если нет, могут ли это сделать какие-то из остальных фигур? Если могут, вывести их список. */

// fig - номер фигуры, (x1; y1) - координаты начала, (x2; y2) - координаты конца
// фигуры: 1–король, 2–ферзь, 3–ладья, 4–слон, 5–конь

#include <stdio.h>
#include <stdlib.h>

int can_move(int fig, int x1, int y1, int x2, int y2) { 
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if (fig == 1) return dx <= 1 && dy <= 1;
    if (fig == 2) return dx == dy || dx == 0 || dy == 0;
    if (fig == 3) return dx == 0 || dy == 0;
    if (fig == 4) return dx == dy;
    if (fig == 5) return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    return 0;
}

int main() {

    char c1[3], c2[3]; // Начальная и конечная клетки

    int fig;
    scanf("%2s %2s %d", c1, c2, &fig);

    // Начальные координаты
    int x1 = c1[0] - 'a';
    int y1 = c1[1] - '1';
    int x2 = c2[0] - 'a';
    int y2 = c2[1] - '1';

    if (can_move(fig, x1, y1, x2, y2)) {
        printf("Yes\n");
    } else {
        printf("No\nCan: ");
        int found = 0;
        for (int i = 1; i <= 5; i++) {
            if (i != fig && can_move(i, x1, y1, x2, y2)) {
                if (found) printf(", ");
                if (i == 1) printf("король");
                if (i == 2) printf("ферзь");
                if (i == 3) printf("ладья");
                if (i == 4) printf("слон");
                if (i == 5) printf("конь");
                found = 1;
            }
        }
        if (!found) printf("никто");
        printf("\n");
    }

    return 0;
}
