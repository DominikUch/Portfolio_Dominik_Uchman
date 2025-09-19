#include <stdio.h>
#define SIZE 100

int main() {
    float T[SIZE];
    float *wdt = T;
    int ilosc;
    printf("Podaj ilosc elementow:\n");
    if (scanf("%d", &ilosc) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if(ilosc <= 0 || ilosc > SIZE){
        printf("Incorrect input data");
        return 2;
    }
    printf("Podaj liczby:\n");
    for (int i = 0; i < ilosc; i++) {
        if (scanf("%f", wdt) != 1) {
            printf("Incorrect input\n");
            return 1;
        }
        wdt++;
    }
    wdt = T + ilosc - 1;
    for (int i = 0; i < ilosc; i++) {
        printf("%.6f ", *wdt);
        wdt--;
    }
    printf("\n");

    wdt = T;
    float suma = 0.0f;
    for (int i = 0; i < ilosc; i++) {
        suma += *wdt;
        wdt++;
    }
    printf("Suma: %.2f\n", suma);
    printf("Srednia: %.2f\n", suma / ilosc);

    return 0;
}