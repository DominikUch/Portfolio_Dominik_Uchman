#include <stdio.h>

int main() {
    int tablica_liczb[100];
    int liczba;
    int ilosc = 0;

    printf("Podaj liczby(nie wiecej niz 1000):\n");
    while (1) {
        if (scanf("%d", &liczba) != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (liczba == 0) {
            if (ilosc < 1) {
                printf("not enough data available");
                return 2;
            } else {
                break;
            }
        }
        if (ilosc >= 100) {
            break;
        }
        tablica_liczb[ilosc] = liczba;
        ilosc++;
    }

    if(ilosc % 2 == 0){
        for(int i = ilosc - 2; i >= 0; i -= 2){
            printf("%d ",tablica_liczb[i]);
        }
    }
    else{
        for(int j = ilosc - 1; j >= 0; j -= 2){
            printf("%d ", tablica_liczb[j]);
        }
    }
    return 0;
}