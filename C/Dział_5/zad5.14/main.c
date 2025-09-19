#include <stdio.h>
#define ROZMIAR 1000

int main() {
    char tablica[ROZMIAR + 1];
    int ilosc =0;
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
    int liczba_wyrazow = 0;
    int wewnatrz_wyrazu = 0;
    for (int i = 0; i < ilosc; i++) {
        if ((tablica[i] >= 'a' && tablica[i] <= 'z') || (tablica[i] >= 'A' && tablica[i] <= 'Z')) {
            wewnatrz_wyrazu = 1;
        } else {
            if (wewnatrz_wyrazu != 0) {
                liczba_wyrazow++;
                wewnatrz_wyrazu = 0;
            }
        }
    }
    if (wewnatrz_wyrazu != 0) {
        liczba_wyrazow++;
    }
    printf("%d\n", liczba_wyrazow);
    return 0;
}