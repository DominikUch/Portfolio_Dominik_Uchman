#include <stdio.h>
#define ROZMIAR 100
int main() {
    int tablica_liczb_A[ROZMIAR];
    int liczba_A;
    int ilosc_A = 0;
    printf("Podaj ciag liczb:\n");
    while (1){
        if(scanf("%d", &liczba_A) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(liczba_A == 0 || ilosc_A >= 100){
            break;
        }
        tablica_liczb_A[ilosc_A] = liczba_A;
        ilosc_A++;
    }
    while(getchar() != '\n');

    int tablica_liczb_B[ROZMIAR];
    int liczba_B;
    int ilosc_B = 0;
    printf("Podaj ciag liczb:\n");
    while (1){
        if(scanf("%d", &liczba_B) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(liczba_B == 0 || ilosc_B >= 100){
            break;
        }
        tablica_liczb_B[ilosc_B] = liczba_B;
        ilosc_B++;
    }
    while(getchar() != '\n');
    if(ilosc_B < 1 || ilosc_A < 1){
        printf("not enough data available");
        return 2;
    }
    int tablica_iloczynu[ROZMIAR];
    if((ilosc_A == ilosc_B) || (ilosc_A < ilosc_B)) {
        for (int i = 0; i < ilosc_A; i++){
            tablica_iloczynu[i] = tablica_liczb_A[i] * tablica_liczb_B[ilosc_B -i - 1];
            printf("%d ", tablica_iloczynu[i]);
        }
    }
    else if(ilosc_A > ilosc_B){
        for (int j = 0; j < ilosc_B; j++){
            tablica_iloczynu[j] = tablica_liczb_A[j] * tablica_liczb_B[ilosc_B -j - 1];
            printf("%d ", tablica_iloczynu[j]);
        }
    }
    return 0;
}