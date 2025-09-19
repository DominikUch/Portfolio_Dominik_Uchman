#include <stdio.h>

#define ROZMIAR_WEJSCIE 100
#define ROZMIAR_WYJSCIE 200

int main() {
    char tablica[ROZMIAR_WEJSCIE + 1];
    int ilosc = 0;
    printf("Podaj tekst:\n");
    while (1) {
        int znak = getchar();
        if (ilosc >= ROZMIAR_WEJSCIE) {
            printf("Input is too long\n");
            return 2;
        }
        if (znak == '\n' || znak == EOF) {
            break;
        } else if ((znak < 'a' || znak > 'z') && (znak < '1' || znak > '9')) {
            printf("Incorrect input\n");
            return 1;
        }
        tablica[ilosc] = (char)znak;
        ilosc++;
    }
    tablica[ilosc] = '\0';
    int dlugosc_wyjscia = 0;
    char wyjscie[ROZMIAR_WYJSCIE];
    for (int i = 0; i < ilosc; i++) {
        if (tablica[i] >= '1' && tablica[i] <= '9') {
            int powtorzenie = tablica[i] - '0';
            for (int j = 0; j < powtorzenie; j++) {
                if (i + 1 < ilosc && tablica[i + 1] >= '1' && tablica[i + 1] <= '9') {
                    printf("Incorrect input\n");
                    return 1;
                }
                wyjscie[dlugosc_wyjscia++] = tablica[i + 1];
                if (dlugosc_wyjscia > ROZMIAR_WYJSCIE) {
                    printf("Output is too long\n");
                    return 3;
                }
            }
            i++;
        } else {
            wyjscie[dlugosc_wyjscia++] = tablica[i];
            if (dlugosc_wyjscia > ROZMIAR_WYJSCIE) {
                printf("Output is too long\n");
                return 3;
            }
        }
    }
    if (ilosc > 0 && tablica[ilosc - 1] >= '1' && tablica[ilosc - 1] <= '9') {
        printf("Incorrect input\n");
        return 1;
    }
    for (int i = dlugosc_wyjscia - 1; i >= 0; i--) {
        printf("%c", wyjscie[i]);
    }
    return 0;
}