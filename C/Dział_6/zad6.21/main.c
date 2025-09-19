#include <stdio.h>
#define ROZMIAR 5

int main() {
    int macierz[ROZMIAR][ROZMIAR];
    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            if (scanf("%d", &macierz[i][j]) != 1) {
                printf("incorrect input\n");
                return 1;
            }
        }
    }
    for (int j = 0; j < ROZMIAR; j++) {
        int suma = 0;
        for (int i = 0; i < ROZMIAR; i++) {
            suma += macierz[i][j];
        }
        double srednia = (double)suma / ROZMIAR;
        printf("%.2f ", srednia);
    }
    return 0;
}