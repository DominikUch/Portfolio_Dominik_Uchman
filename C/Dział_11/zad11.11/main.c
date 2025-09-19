#include <stdio.h>
#include "letter_changer.h"

#define SIZE 1000

int main() {
    char tablica[SIZE + 1];
    int ilosc = 0;

    printf("Podaj tekst:\n");
    char *wskaznik = tablica;
    while (1) {
        int znak = getchar();
        if (ilosc >= SIZE || znak == '\n' || znak == EOF) {
            break;
        }
        *wskaznik = (char)znak;
        wskaznik++;
        ilosc++;
    }
    *wskaznik = '\0';

    char litera;
    while (1) {
        printf("Jesli wielkie wcisnij: B, male: S\n");
        int temp = getchar();
        if (temp == '\n' || temp == EOF) {
            break;
        }
        litera = (char)temp;
        if (litera == 'B' || litera == 'b') {
            change_letter_size(tablica, TO_UPPER);
            break;
        } else if (litera == 'S' || litera == 's') {
            change_letter_size(tablica, TO_LOWER);
            break;
        } else {
            printf("Incorrect input\n");
            while (getchar() != '\n');
        }
    }
    printf("%s\n", tablica);

    return 0;
}