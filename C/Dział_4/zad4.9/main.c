#include <stdio.h>

int main() {
#define wielkosc_tablicy 100
    int liczby[wielkosc_tablicy];
    int ilosc = 0;
    int min = 0;
    int max = 0;
    int suma = 0;
    printf("Podaj liczby:");
    while (1){
        if(scanf("%d", &liczby[ilosc]) != 1){
            printf("Incorrect input");
            return 1;
        }
        if(ilosc >= 100){
            break;
        }
        if (liczby[ilosc] == -1){
            break;
        }
        if(ilosc == 0){
            min = max = liczby[ilosc];
        }
        else{
            if(liczby[ilosc] > max){
                max = liczby[ilosc];
            }
            if(liczby[ilosc] < min){
                min = liczby[ilosc];
            }
        }
        suma = suma + liczby[ilosc];
        ilosc++;
    }
    float srednia = suma / (float)ilosc;

    printf("%d\n", ilosc);
    printf("%d\n", min);
    printf("%d\n", max);
    printf("%f\n", srednia);
    printf("%d\n", suma);
    return 0;
}