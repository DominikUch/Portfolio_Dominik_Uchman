#include <stdio.h>
#define ROZMIAR 10

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
    int suma_parzystych = 0;
    int suma_nieparzystych = 0;
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            if ((i + j) % 2 == 0) {
                suma_parzystych += tablica[i][j];
            } else {
                suma_nieparzystych += tablica[i][j];
            }
        }
    }
    int odejmowanie = suma_parzystych - suma_nieparzystych;
    printf("%d\n", odejmowanie);
    return 0;
}