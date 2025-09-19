#include <stdio.h>
#define ROZMIAR 1000
int main() {
    int tablica_liczb[ROZMIAR];
    int liczba;
    int ilosc = 0;
    printf("Podaj ciag liczb:\n");
    while (1){
        if(scanf("%d", &liczba) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(liczba == 0 || ilosc >= 1000){
            break;
        }
        tablica_liczb[ilosc] = liczba;
        ilosc++;
    }
    while(getchar() != '\n');
    if(ilosc < 2){
        printf("not enough data available");
        return 2;
    }
    int wyniki[ROZMIAR];
    if(ilosc % 2 == 0){
     for(int i = 1; i < (ilosc / 2) + 1 ; i++){
         wyniki[i] = tablica_liczb[ilosc - i] - (tablica_liczb[i - 1]);
         printf("%d ", wyniki[i]);
        }
    }
    else{
        int ilosc_do_mediany = 0;
        for(int i = 1; i < (ilosc / 2) + 1 ;i++){
            ilosc_do_mediany += 1;
            wyniki[i] = (tablica_liczb[ilosc - i] - (tablica_liczb[i - 1]));
            printf("%d ", wyniki[i]);
        }
        printf("%d", tablica_liczb[ilosc_do_mediany]);
    }
    return 0;
}