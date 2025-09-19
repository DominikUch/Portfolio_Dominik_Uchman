
#include <stdio.h>
int main(){
    int tablica_liczb[1000];
    int liczba;
    int ilosc = 0;
    printf("Podaj liczby(nie wiecej niz 1000):\n");
    while (1) {
    if(scanf("%d", &liczba) != 1){
        printf("Incorrect input");
        return 1;
    }
    if(liczba == 0){
        if(ilosc < 2){
            printf("not enough data available");
            return 2;
        }
        else {
            break;
        }
    }
    if(ilosc >= 1000){
        break;
    }
    ilosc++;
    tablica_liczb[ilosc] = liczba;
    }
    float srednia[1000];
    for (int i = 1; i < ilosc; i += 1){
        srednia[i] =((float)tablica_liczb[i] + (float)tablica_liczb[i+1])/2;
        printf("%.2f ", srednia[i]);
    }
    return 0;
}

