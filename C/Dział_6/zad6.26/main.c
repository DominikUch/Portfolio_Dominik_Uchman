#include <stdio.h>
#define ROZMIAR_A 10
#define ROZMIAR_B 2

int main() {
    int macierz_a[ROZMIAR_A][ROZMIAR_A];
    printf("Podaj liczby\n");
    for (int i = 0; i < ROZMIAR_A; i++) {
        for (int j = 0; j < ROZMIAR_A; j++) {
            if (scanf("%d", &macierz_a[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    int macierz_b[ROZMIAR_B][ROZMIAR_B];
    printf("Podaj liczby:\n");
    for (int i = 0; i < ROZMIAR_B; i++) {
        for (int j = 0; j < ROZMIAR_B; j++) {
            if (scanf("%d", &macierz_b[i][j]) != 1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    int licznik = 0;
    for (int i = 0; i <= ROZMIAR_A - ROZMIAR_B; i++) {
        for (int j = 0; j <= ROZMIAR_A - ROZMIAR_B; j++) {
            int znaleziona = 1;

            for (int x = 0; x < ROZMIAR_B; x++) {
                for (int y = 0; y < ROZMIAR_B; y++) {
                    if (macierz_a[i + x][j + y] != macierz_b[x][y]) {
                        znaleziona = 0;
                        break;
                    }
                }
                if (znaleziona == 0) {
                    break;
                }
            }
            if (znaleziona == 1) {
                licznik++;
            }
        }
    }
    printf("%d\n", licznik);
    for (int i = 0; i <= ROZMIAR_A - ROZMIAR_B; i++) {
        for (int j = 0; j <= ROZMIAR_A - ROZMIAR_B; j++) {
            int znaleziona = 1;

            for (int x = 0; x < ROZMIAR_B; x++) {
                for (int y = 0; y < ROZMIAR_B; y++) {
                    if (macierz_a[i + x][j + y] != macierz_b[x][y]) {
                        znaleziona = 0;
                        break;
                    }
                }
                if (znaleziona == 0) {
                    break;
                }
            }
            if (znaleziona == 1) {
                printf("%d %d\n", j, i);
            }
        }
    }
}