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
        if ((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z') || znak == ' ' || znak == '\t') {
            tablica[ilosc] = (char) znak;
            ilosc++;
        } else {
            printf("Incorrect input\n");
            return 1;
        }
    }
    tablica[ilosc] = '\0';
    int zliczenia[26] = {0};
    for (int i = 0; tablica[i] != '\0'; ++i) {
        char obecny_znak = tablica[i];
        if(obecny_znak >= 'A' && obecny_znak <= 'Z'){
            obecny_znak = obecny_znak + ('a' - 'A');
        }
        if (obecny_znak >= 'a' && obecny_znak <= 'z') {
            zliczenia[obecny_znak - 'a']++;
        }
    }
    for (int j = 0; j < 26; ++j) {
        char obecna_litera = 'a' + j;
        printf("%c - %d\n", obecna_litera, zliczenia[j]);
        }
    return 0;
}