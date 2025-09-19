#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR 4
int main() {
    srand(time(NULL));
    int macierz_a[ROZMIAR][ROZMIAR];
    int macierz_b[ROZMIAR][ROZMIAR];
    int macierz_c[ROZMIAR][ROZMIAR] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            macierz_a[i][j] = rand() % 10;
            macierz_b[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            printf("%d ", macierz_a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            printf("%d ", macierz_b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            printf("%d ", macierz_c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < ROZMIAR; i++) {
        int suma_wierszy = 0;
        for (int j = 0; j < ROZMIAR; j++) {
            suma_wierszy += macierz_a[i][j];
        }
        printf("%d ", suma_wierszy);
    }
    printf("\n");
    for (int j = 0; j < ROZMIAR; j++) {
        int suma_kolumn = 0;
        for (int i = 0; i < ROZMIAR; i++) {
            suma_kolumn += macierz_a[i][j];
        }
        printf("%d ", suma_kolumn);
    }
    printf("\n");
    for (int i = 0; i < ROZMIAR; i++) {
        int suma_wierszy = 0;
        for (int j = 0; j < ROZMIAR; j++) {
            suma_wierszy += macierz_b[i][j];
        }
        printf("%d ", suma_wierszy);
    }
    printf("\n");
    for (int j = 0; j < ROZMIAR; j++) {
        int suma_kolumn = 0;
        for (int i = 0; i < ROZMIAR; i++) {
            suma_kolumn += macierz_b[i][j];
        }
        printf("%d ", suma_kolumn);
    }
    printf("\n");
    for (int i = 0; i < ROZMIAR; i++) {
        int suma_wierszy = 0;
        for (int j = 0; j < ROZMIAR; j++) {
            suma_wierszy += macierz_c[i][j];
        }
        printf("%d ", suma_wierszy);
    }
    printf("\n");
    for (int j = 0; j < ROZMIAR; j++) {
        int suma_kolumn = 0;
        for (int i = 0; i < ROZMIAR; i++) {
            suma_kolumn += macierz_c[i][j];
        }
        printf("%d ", suma_kolumn);
    }
    printf("\n");
    return 0;
}