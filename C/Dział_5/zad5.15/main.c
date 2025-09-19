#include <stdio.h>
#define ROZMIAR 1000

int main() {
    char tablica[ROZMIAR + 1];
    int ilosc = 0;
    int znak;
    printf("Podaj tekst:\n");

    while (1) {
        znak = getchar();
        if (znak == '\n' || znak == EOF || ilosc >= ROZMIAR) {
            break;
        }
        tablica[ilosc] = (char)znak;
        ilosc++;
    }
    tablica[ilosc] = '\0';
    int dlugosc_slowa[ROZMIAR] = {0};
    int dlugosc_obecne_slowo = 0;
    int wewnatrz = 0;

    for (int i = 0; i <= ilosc; i++) {
        if ((tablica[i] >= 'a' && tablica[i] <= 'z') || (tablica[i] >= 'A' && tablica[i] <= 'Z')) {
            dlugosc_obecne_slowo++;
            wewnatrz = 1;
        } else {
            if (wewnatrz != 0) {
                dlugosc_slowa[dlugosc_obecne_slowo - 1]++;
                dlugosc_obecne_slowo = 0;
                wewnatrz = 0;
            }
        }
    }
    for (int i = 0; i < ROZMIAR; i++) {
        if (dlugosc_slowa[i] > 0) {
            printf("%d - %d\n", i + 1, dlugosc_slowa[i]);
        }
    }
    return 0;
}