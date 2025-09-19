#include <stdio.h>

#define WIERSZ 5
#define KOLUMNA 5

int main() {
    int macierz[WIERSZ][KOLUMNA];
    printf("Podaj liczby:\n");
    for (int i = 0; i < WIERSZ; i++) {
        for (int j = 0; j < KOLUMNA; j++) {
            if (scanf("%d", &macierz[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
        }
    }
    int roznica_max = 0;
    int kolumny_z_max_roznica[KOLUMNA];
    int liczba_kolumn_z_max_roznica = 0;
    for (int j = 0; j < KOLUMNA; j++) {
        int max = macierz[0][j];
        int min = macierz[0][j];
        for (int i = 1; i < WIERSZ; i++) {
            if (macierz[i][j] > max) {
                max = macierz[i][j];
            }
            if (macierz[i][j] < min) {
                min = macierz[i][j];
            }
        }
        int roznica = max - min;
        if (roznica > roznica_max) {
            roznica_max = roznica;
            kolumny_z_max_roznica[0] = j;
            liczba_kolumn_z_max_roznica = 1;
        } else if (roznica == roznica_max) {
            kolumny_z_max_roznica[liczba_kolumn_z_max_roznica] = j;
            liczba_kolumn_z_max_roznica++;
        }
    }
    for (int k = 0; k < liczba_kolumn_z_max_roznica; k++) {
        for (int i = 0; i < WIERSZ; i++) {
            printf("%d ", macierz[i][kolumny_z_max_roznica[k]]);
        }
        printf("\n");
    }
    return 0;
}