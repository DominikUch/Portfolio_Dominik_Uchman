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

    int wynik_ab[ROZMIAR][ROZMIAR] = {0};
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            for (int k = 0; k < ROZMIAR; k++) {
                wynik_ab[i][j] += macierz_a[i][k] * macierz_b[k][j];
            }
            printf("%d ", wynik_ab[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int wynik_ba[ROZMIAR][ROZMIAR] = {0};
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            for (int k = 0; k < ROZMIAR; k++) {
                wynik_ba[i][j] += macierz_b[i][k] * macierz_a[k][j];
            }
            printf("%d ", wynik_ba[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int wynik_ac[ROZMIAR][ROZMIAR] = {0};
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            for (int k = 0; k < ROZMIAR; k++) {
                wynik_ac[i][j] += macierz_a[i][k] * macierz_c[k][j];
            }
            printf("%d ", wynik_ac[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int wynik_ca[ROZMIAR][ROZMIAR] = {0};
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            for (int k = 0; k < ROZMIAR; k++) {
                wynik_ca[i][j] += macierz_c[i][k] * macierz_a[k][j];
            }
            printf("%d ", wynik_ca[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

