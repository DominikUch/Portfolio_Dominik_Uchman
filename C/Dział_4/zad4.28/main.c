#include  <stdio.h>
#define ROZMIAR 100

int main() {
    int tablica_liczb[ROZMIAR];
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
    int ilosc_index_max = 1;
    int min = tablica_liczb[0];
    int index_max = 0;
    int ilosc_index_min = 1;
    int max = tablica_liczb[0];

    for(int i = 1; i < ilosc; i++) {
        if (tablica_liczb[i] > max) {
            max = tablica_liczb[i];
            index_max = i;
            ilosc_index_max = 1;
        }else if (tablica_liczb[i] == max) {
            index_max += i;
            ilosc_index_max += 1;
        }
        if (tablica_liczb[i] < min) {
            min = tablica_liczb[i];
            index_min = i;
            ilosc_index_min = 1;
        }else if (tablica_liczb[i] == min) {
            index_min += i;
            ilosc_index_min += 1;
        }
    }
    int srednia = (index_max + index_min) / (ilosc_index_max + ilosc_index_min);
    printf("%d", tablica_liczb[srednia]);
    return 0;
}