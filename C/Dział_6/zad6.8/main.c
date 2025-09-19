#include <stdio.h>
#define ROZMIAR 15
int main() {
    int tablica[ROZMIAR][ROZMIAR];
    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            if (scanf("%d", &tablica[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
            if (tablica[i][j] < 0 || tablica[i][j] >= 30) {
                printf("value out of range\n");
                return 2;
            }
        }
    }
    int wynik[ROZMIAR][ROZMIAR] = {0};
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            int obecny_element = tablica[i][j];
            int zliczenia = 0;
            for (int m = 0; m < ROZMIAR; ++m) {
                for (int n = 0; n < ROZMIAR; ++n) {
                    if (m == i && n == j) {
                        continue;
                    }
                    if (tablica[m][n] == obecny_element) {
                        ++zliczenia;
                    }
                }
            }
            wynik[i][j] = zliczenia + 1;
        }
    }
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            printf("%2d ", wynik[i][j]);
        }
        printf("\n");
    }
    return 0;
}