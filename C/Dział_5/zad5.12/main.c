#include <stdio.h>
#define ROZMIAR 100

int main() {
    char tablica[ROZMIAR + 1];
    int ilosc = 0;
    printf("Podaj tekst:\n");
    int znak;
    while (1) {
        znak = getchar();
        if (znak == '\n' || znak == EOF || ilosc >= ROZMIAR) {
            break;
        }
        if ((znak < '0' || znak > '9') && znak != '+' && znak != '-') {
            printf("Incorrect input\n");
            return 1;
        }
        tablica[ilosc] = (char)znak;
        ilosc++;
    }
    tablica[ilosc] = '\0';
    int suma = 0;
    int liczba = 0;
    int operacja = 1;

    for (int i = 0; tablica[i] != '\0'; i++) {
        if (tablica[i] >= '0' && tablica[i] <= '9') {
            liczba = liczba * 10 + (tablica[i] - '0');
        } else if (tablica[i] == '+') {
            suma += operacja * liczba;
            liczba = 0;
            operacja = 1;
        } else if (tablica[i] == '-') {
            suma += operacja * liczba;
            liczba = 0;
            operacja = -1;
        }
    }
    suma += operacja * liczba;
    printf("%d\n", suma);
    return 0;
}