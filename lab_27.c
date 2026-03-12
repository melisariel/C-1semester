/* Технические требования:
    При разработке программы должен быть использован механизм функций языка С.
    В программе должен быть использован тип указатель на функцию.
    Каждый студент должен реализовать расчет функций sin(x), cos(x), exp(x) и поместить их в библиотеку mylib.h. 

Разработать программу, позволяющую выполнять расчет значений для  набора функций в заданной точке с заданной погрешностью за счет разложения этих функций в ряд Тейлора.
Функции поместить в библиотеку mylib.h
Программа должна обращаться к библиотеке mylib.h и работать в двух режимах с использованием цветного меню:

1. Однократный расчет функции в заданной точке.
2. Серийный эксперимент.

При работе в режиме 1 пользователь должен иметь возможность:

    выбрать функцию,
    задать точку x, в которой необходимо вычислить значение,
    задать точность вычисления (от 0.000001 и больше),
    задать число элементов ряда для выполнения расчета (N - от 1 до 1000).

Расчет оценки значения выбранной функции выполняется либо до достижения заданной точности, либо до исчерпания введенного числа слагаемых. По результатам расчета программа должна вывести следующую информацию:

    эталонное значение (полученное с использованием встроенных математических функций языка программирования С),
    вычисленную оценку значения функции,
    разницу между оценкой и эталонным значением,
    количество слагаемых, которое было вычислено.

При работе в режиме 2 пользователь должен иметь возможность:

    выбрать функцию,
    задать точку x, в которой необходимо вычислить значение,
    задать число экспериментов (NMax - от 1 до 5 для разных значений N.)

По результатам расчета программа должна вывести следующую информацию:

    эталонное значение (полученное с использованием встроенных математических функций языка программирования С),
    таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), вычисленную оценку значения функции, разницу между оценкой и эталонным значением. */


// Программа
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "mylib.h"

int menu(char** items, int n) {
    int selected = 0;
    int code;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    WORD menuColor = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD activeColor = BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    do {
        system("cls");
        for (int i = 0; i < n; i++) {
            if (i == selected) {
                SetConsoleTextAttribute(console, activeColor);
                printf("  %s  \n", items[i]);
            } else {
                SetConsoleTextAttribute(console, menuColor);
                printf("  %s  \n", items[i]);
            }
        }

        code = _getch();
        if (code == 0 || code == 224)
            code = _getch();

        if (code == 72) {
            selected--;
            if (selected < 0) selected = n - 1;
        } else if (code == 80) {
            selected++;
            if (selected >= n) selected = 0;
        }

    } while (code != 13);

    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return selected;
}

typedef double (*FuncPtr)(double, double, int, int*);


void single_calculation() {
    char* funcs[] = { "sin(x)", "cos(x)", "exp(x)" };
    int choice = menu(funcs, 3);

    FuncPtr f = NULL;
    double (*standard_f)(double) = NULL;
    switch(choice) {
        case 0: f = my_sin; standard_f = sin; break;
        case 1: f = my_cos; standard_f = cos; break;
        case 2: f = my_exp; standard_f = exp; break;
        default: return;
    }

    double x, eps;
    int N;
    printf("x: "); scanf("%lf", &x);
    printf("eps (>=0.000001): "); scanf("%lf", &eps);
    printf("N (1-1000): "); scanf("%d", &N);

    int terms;
    double approx = f(x, eps, N, &terms);
    double exact = standard_f(x);
    double diff = fabs(exact - approx);

    printf("\nTochnoe znach: %lf\n", exact);
    printf("Ocenka znacheni: %lf\n", approx);
    printf("Raznica: %lf\n", diff);
    printf("Colichestvo: %d\n", terms);
    system("pause");
}

void series_experiment() {
    char* funcs[] = { "sin(x)", "cos(x)", "exp(x)" };
    int choice = menu(funcs, 3);

    FuncPtr f = NULL;
    double (*standard_f)(double) = NULL;
    switch(choice) {
        case 0: f = my_sin; standard_f = sin; break;
        case 1: f = my_cos; standard_f = cos; break;
        case 2: f = my_exp; standard_f = exp; break;
        default: return;
    }

    double x;
    int NMax;
    printf("x: "); scanf("%lf", &x);
    printf("NMax (1-5): "); scanf("%d", &NMax);

    double exact = standard_f(x);
    printf("\nTochnoe znach %lf\n", exact);
    printf(" N\tOcenka znacheni\tRaznica\n");

    for(int N = 1; N <= NMax; N++) {
        int terms;
        double approx = f(x, 1e-12, N, &terms);
        double diff = fabs(exact - approx);
        printf("%d\t%lf\t%lf\n", N, approx, diff);
    }
    system("pause");
}

int main() {
    int n = 3;
    char* items[] = { "Exit", "Calculation", "Experiment" };
    int choice;

    do {
        choice = menu(items, n);

        switch(choice) {
            case 0: break;
            case 1: single_calculation(); break;
            case 2: series_experiment(); break;
        }

    } while(choice != 0);

    return 0;
}

// Библиотека
#ifndef MYLIB_H
#define MYLIB_H

#include <math.h>
#include <stdio.h>

double my_sin(double x, double eps, int N, int *terms_used)
{
    double term = x;
    double sum = term;
    int n = 1;
    while (fabs(term) > eps && n < N) {
        term *= -x*x / ((2*n)*(2*n+1));
        sum += term;
        n++;
    }
    *terms_used = n;
    return sum;
}

double my_cos(double x, double eps, int N, int *terms_used)
{
    double term = 1;
    double sum = term;
    int n = 1;
    while (fabs(term) > eps && n < N) {
        term *= -x*x / ((2*n-1)*(2*n));
        sum += term;
        n++;
    }
    *terms_used = n;
    return sum;
}

double my_exp(double x, double eps, int N, int *terms_used)
{
    double term = 1;
    double sum = term;
    int n = 1;
    while (fabs(term) > eps && n < N) {
        term *= x / n;
        sum += term;
        n++;
    }
    *terms_used = n;
    return sum;
}

#endif
