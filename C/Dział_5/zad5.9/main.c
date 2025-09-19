#include <stdio.h>

#define ROZMIAR 1000
#define ROZMIAR_CIAGU_WEJSCIOWEGO 100
#define ROZMIAR_CIAGU_WYJSCIOWEGO 200

int main() {
    char tablica[ROZMIAR+1];
    int ilosc = 0;
    printf("Podaj tekst:\n");
    while (1) {
        int znak = getchar();
        if (znak == '\n' || znak == EOF || ilosc >= ROZMIAR) {
            break;
        }
        tablica[ilosc] = (char)znak;
        ilosc++;
    }
    tablica[ilosc] = '\0';
    for (int i = 0; i < ilosc; ++i) {
        if ((tablica[i] < 'a' || tablica[i] > 'z') && (tablica[i] <'A' || tablica[i] >'Z')) {
            printf("Incorrect input\n");
            return 1;
        }
    }
    if (ilosc > ROZMIAR_CIAGU_WEJSCIOWEGO ) {
        printf("Input is too long\n");
        return 2;
    }
    char wynik[ROZMIAR_CIAGU_WYJSCIOWEGO + 1];
    int wynik_index = 0;
    for (int i = ilosc - 1; i >= 0; --i) {
        int powtorzenia;
        if (tablica[i] >= 'A' && tablica[i] <= 'Z') {
            powtorzenia = 3;
        } else {
            powtorzenia = 1;
        }
        for (int j = 0; j < powtorzenia; ++j) {
            if (wynik_index < ROZMIAR_CIAGU_WYJSCIOWEGO) {
                wynik[wynik_index] = tablica[i];
                wynik_index++;
            } else {
                printf("Output is too long\n");
                return 3;
            }
        }
    }
    wynik[wynik_index] = '\0';
    printf("%s\n", wynik);
    return 0;
}