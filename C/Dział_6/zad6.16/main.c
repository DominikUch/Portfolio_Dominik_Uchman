#include <stdio.h>

#define WIERSZ 5
#define KOLUMNY 5

int main() {
    int macierz[WIERSZ][KOLUMNY];
    int suma_kolumn[KOLUMNY] = {0};
    printf("Podaj liczby:\n");
    for (int i = 0; i < WIERSZ; i++) {
        for (int j = 0; j < KOLUMNY; j++) {
            if (scanf("%d", &macierz[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
        }
    }
    for (int j = 0; j < KOLUMNY; j++) {
        for (int i = 0; i < WIERSZ; i++) {
            suma_kolumn[j] += macierz[i][j];
        }
    }
    int suma_max = suma_kolumn[0];
    for (int j = 1; j < KOLUMNY; j++) {
        if (suma_kolumn[j] > suma_max) {
            suma_max = suma_kolumn[j];
        }
    }
    for (int j = 0; j < KOLUMNY; j++) {
        if (suma_kolumn[j] == suma_max) {
            for (int i = 0; i < WIERSZ; i++) {
                printf("%d ", macierz[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}