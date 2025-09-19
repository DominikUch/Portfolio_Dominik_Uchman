#include <stdio.h>
#define ROZMIAR 50

int main() {
    char tablica[ROZMIAR + 1];
    int ilosc = 0;
    int suma = 0;
    printf("Podaj tekst:\n");
    while (1) {
        int znak = getchar();
        if (znak == '\n' || znak == EOF || ilosc >= ROZMIAR) {
            break;
        } else if (znak != '(' && znak != ')' && znak != ' ') {
            printf("Incorrect input");
            return 1;
        }
        tablica[ilosc] = (char)znak;
        ilosc++;
    }
    tablica[ilosc] = '\0';
    for (int i = 0; tablica[i] != '\0'; i++) {
        if (tablica[i] == '(') {
            suma++;
        } else if (tablica[i] == ')') {
            suma--;
            if (suma < 0) {
                printf("Niepoprawny\n");
                return 0;
            }
        }
    }
    if (suma == 0) {
        printf("Poprawny\n");
    } else {
        printf("Niepoprawny\n");
    }
    return 0;
}