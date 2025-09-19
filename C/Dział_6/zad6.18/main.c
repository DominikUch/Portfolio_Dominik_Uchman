#include <stdio.h>
#define ROZMIAR 5

int main() {
    int macierz_A[ROZMIAR][ROZMIAR];
    int macierz_B[ROZMIAR][ROZMIAR];
    int macierz_C[ROZMIAR][ROZMIAR];

    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            if (scanf("%d", &macierz_A[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
        }
    }

    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            if (scanf("%d", &macierz_B[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
        }
    }
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            if (macierz_A[i][j] > macierz_B[i][j]) {
                macierz_C[i][j] = macierz_A[i][j];
            } else {
                macierz_C[i][j] = macierz_B[i][j];
            }
        }
    }

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            printf("%d ", macierz_C[i][j]);
        }
        printf("\n");
    }
    return 0;
}