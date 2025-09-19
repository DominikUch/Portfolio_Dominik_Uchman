#include <stdio.h>
#define ROZMIAR 5

int main() {
    int tablica[ROZMIAR][ROZMIAR];
    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            if (scanf("%d", &tablica[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    int suma = 0;
    for (int i = 1; i < ROZMIAR - 1; ++i) {
        suma += tablica[i][0];
        suma += tablica[i][ROZMIAR - 1];
    }
    for (int j = 0; j < ROZMIAR; ++j) {
        suma += tablica[0][j];
        suma += tablica[ROZMIAR - 1][j];
    }
    printf("%d\n", suma);
    return 0;
}
