#include <stdio.h>
#define ROZMIAR 1000

int main() {
    char tablica[ROZMIAR + 1];
    int ilosc = 0;
    printf("Podaj tekst:\n");
    int znak;
    while ((znak = getchar()) != EOF && znak != '\n' && ilosc < ROZMIAR) {
        if ((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z') || znak == ' ') {
            tablica[ilosc] = (char)znak;
            ilosc++;
        } else {
            printf("Incorrect input\n");
            return 1;
        }
    }
    tablica[ilosc] = '\0';
    int krok_przesuniecie;
    printf("Podaj znak kodowy:\n");
    scanf("%d", &krok_przesuniecie);
    while (getchar() != '\n');

    for (int i = 0; tablica[i] != '\0'; i++) {
        if ((tablica[i] >= 'a' && tablica[i] <= 'z') || (tablica[i] >= 'A' && tablica[i] <= 'Z')) {
            char litera;
            if (tablica[i] >= 'a' && tablica[i] <= 'z') {
                litera = 'a';
            } else {
                litera = 'A';
            }
            tablica[i] = (tablica[i] - litera + krok_przesuniecie) % 26 + litera;
        }
    }
    printf("%s\n", tablica);
    return 0;
}