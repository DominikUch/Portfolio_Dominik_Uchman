#include <stdio.h>
#define ROZMIAR 5

int main() {
    int macierz[ROZMIAR][ROZMIAR];
    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            if (scanf("%d", &macierz[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
        }
    }
    for (int i = 0; i < ROZMIAR; ++i) {
        int max_wiersza = macierz[i][0];
        for (int j = 1; j < ROZMIAR; ++j) {
            if (macierz[i][j] > max_wiersza) {
                max_wiersza = macierz[i][j];
            }
        }
        printf("%d ", max_wiersza);
    }
    for (int j = 0; j < ROZMIAR; ++j) {
        int max_kolumny = macierz[0][j];
        for (int i = 1; i < ROZMIAR; ++i) {
            if (macierz[i][j] > max_kolumny) {
                max_kolumny = macierz[i][j];
            }
        }
        printf("%d ", max_kolumny);
    }
    return 0;
}