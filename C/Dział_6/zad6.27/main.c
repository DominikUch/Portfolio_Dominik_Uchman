#include <stdio.h>
#define WIERSZ 5
#define KOLUMNY 10

int main() {
    int macierz[WIERSZ][KOLUMNY];

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
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
    return 0;
}