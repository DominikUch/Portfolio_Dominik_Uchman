#include <stdio.h>
#define ROZMIAR 1000
int main() {
    char tablica[ROZMIAR + 1];
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
    for (int i = 0; tablica[i] != '\0'; i++) {
        if ((tablica[i] < '0' || tablica[i] > '9') && tablica[i] != '|' && tablica[i] != '-') {
            printf("Incorrect input\n");
            return 1;
        }
    }
    long suma = 0;
    long sumy[ROZMIAR];
    int index = 0;
    for (int i = 0; tablica[i] != '\0'; i++) {
        if (tablica[i] == '|') {
            sumy[index++] = suma;
            suma = 0;
        } else if (tablica[i] >= '0' && tablica[i] <= '9') {
            int liczba = tablica[i] - '0';
            while (tablica[i + 1] >= '0' && tablica[i + 1] <= '9') {
                liczba = liczba * 10 + (tablica[++i] - '0');
            }
            suma += liczba;
        }
    }
    sumy[index++] = suma;
    for (int i = 0; i < index; i++) {
        printf("%ld ",sumy[i]);
    }
    return 0;
}