
#include <stdio.h>
#define KOLUMNA 5
#define WIERSZ 5
#define PRZEKATNA 5
    int main() {
        int macierz[5][5];
        printf("Wprowadz 25 liczb dla macierzy 5x5:\n");
        for (int i = 0; i < KOLUMNA; i++) {
            for (int j = 0; j < WIERSZ; j++) {
                if (scanf("%d", &macierz[i][j]) != 1) {
                    printf("Incorrect input\n");
                    return 1;
                }
            }
        }
        for (int i = 0; i < PRZEKATNA; i++) {
            int tymczasowa = macierz[i][i];
            macierz[i][i] = macierz[i][4 - i];
            macierz[i][4 - i] = tymczasowa;
        }
        for (int i = 0; i < KOLUMNA; i++) {
            for (int j = 0; j < WIERSZ ; j++) {
                printf("%d ", macierz[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
