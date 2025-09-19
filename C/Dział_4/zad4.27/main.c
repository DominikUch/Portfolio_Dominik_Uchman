#include  <stdio.h>

int main() {
    int tablica_liczb[100];
    int liczba;
    int ilosc = 0;
    printf("Podaj ciag liczb:\n");
    while (1) {
        if (scanf("%d", &liczba) != 1) {
            printf("incorrect input");
            return 1;
        }
        if (liczba == 0 || ilosc >= 100) {
            break;
        }
        tablica_liczb[ilosc] = liczba;
        ilosc++;
    }
    while (getchar() != '\n');
    if (ilosc < 2) {
        printf("not enough data available");
        return 2;
    }
    int index_min = 0;
    int min = tablica_liczb[0];
    int index_max = 0;
    int max = tablica_liczb[0];

    for(int i = 0; i < ilosc; i++) {
        if (tablica_liczb[i] > max) {
            max = tablica_liczb[i];
            index_max = i;
        } else if (tablica_liczb[i] == max) {
            continue;
        }
        if (tablica_liczb[i] < min) {
            min = tablica_liczb[i];
            index_min = i;
        } else if (tablica_liczb[i] == min) {
            continue;
        }
    }
    int srednia = (index_max + index_min) / 2;
    if(srednia <= ilosc){
        printf("%d", tablica_liczb[srednia]);
        return 0;
    }
}