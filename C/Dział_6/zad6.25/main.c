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
    int suma = 0;
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = i; j < ROZMIAR; j++) {
            suma += macierz[i][j];
        }
    }
    printf("%d\n", suma);
    return 0;
}