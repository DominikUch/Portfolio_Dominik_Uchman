#include <stdio.h>
int main(){
    int tablica_liczb[100];
    int ilosc = 0;
    int liczba;
    printf("Podaj liczby(nie wiecej niz 100):\n");
    while (1){
        if((scanf("%d", &liczba)) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(ilosc >= 100){
            break;
        }
        if(liczba == 0){
            if(ilosc < 1){
                printf("not enough data available");
                return 2;
            }
            else{
                break;
            }
        }
        tablica_liczb[ilosc] = liczba;
        ilosc++;
    }
    while (getchar() != '\n');

    printf("Podaj wartosc referencyjna:\n");
    int wartosc_referencyjna;
    if(scanf("%d", &wartosc_referencyjna) != 1){
        printf("Incorrect input");
        return 1;
    }
    int liczba_mniejszych = 0;
    int liczba_wiekszych = 0;
    for(int i = 0; i < ilosc; i++){
        if(tablica_liczb[i] > wartosc_referencyjna){
            liczba_wiekszych++;
        }
        else if(tablica_liczb[i] < wartosc_referencyjna){
            liczba_mniejszych++;
        }
    }
    printf("%d\n", liczba_mniejszych);
    printf("%d\n", liczba_wiekszych);
    return 0;
}