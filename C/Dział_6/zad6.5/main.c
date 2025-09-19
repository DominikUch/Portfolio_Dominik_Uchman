#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR 4

int main() {
    srand(time(NULL));
    int macierz_a[ROZMIAR][ROZMIAR];
    int macierz_b[ROZMIAR][ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            macierz_a[i][j] = rand() % 10;
            macierz_b[i][j] = rand() % 10;
        }
    }
    int macierz_c[ROZMIAR][ROZMIAR] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

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
    int suma_2[ROZMIAR][ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            suma_2[i][j] = macierz_a[i][j] + macierz_b[i][j];
            printf("%d ", suma_2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int roznica_2[ROZMIAR][ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            roznica_2[i][j] = macierz_a[i][j] - macierz_b[i][j];
            printf("%d ", roznica_2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int suma_3[ROZMIAR][ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            suma_3[i][j] = macierz_a[i][j] + macierz_b[i][j] + macierz_c[i][j];
            printf("%d ", suma_3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int roznica_3[ROZMIAR][ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            roznica_3[i][j] = macierz_a[i][j] - macierz_b[i][j] - macierz_c[i][j];
            printf("%d ", roznica_3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int minusowa_macierz[ROZMIAR][ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            minusowa_macierz[i][j] = (-1) * macierz_b[i][j];
            printf("%d ", minusowa_macierz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

