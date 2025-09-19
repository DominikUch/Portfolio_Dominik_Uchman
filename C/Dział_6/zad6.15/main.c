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
    int glowna_przekatna = 0;
    for (int i = 0; i < ROZMIAR; i++) {
        glowna_przekatna += macierz[i][i];
    }
    printf("%d ", glowna_przekatna);
    int druga_przekatna = 0;
    for (int i = 0; i < ROZMIAR; i++) {
        druga_przekatna += macierz[i][ROZMIAR - 1 - i];
    }
    printf("%d ", druga_przekatna);
    return 0;
}