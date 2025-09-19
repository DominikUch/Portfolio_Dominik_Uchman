#include <stdio.h>
#define ROZMIAR 10

int main() {
    char tablica[ROZMIAR + 1];
    int ilosc = 0;
    printf("Podaj imie:\n");
    int znak;
    while (1){
        znak = getchar();
        if(znak == '\n' || znak == EOF || ilosc >= ROZMIAR){
            break;
        }
        tablica[ilosc] = (char)znak;
        ilosc++;
    }
    tablica[ilosc] = '\0';
    if(ilosc > 0 && ilosc <= ROZMIAR){
        if(tablica[ilosc - 1] == 'a'){
            printf("Imie zenskie");
        }
        else{
            printf("Imie meskie");
        }
    }
    return 0;
}